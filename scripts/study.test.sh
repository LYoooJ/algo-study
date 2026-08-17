#!/usr/bin/env bash

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CLI="${SCRIPT_DIR}/study"
TEST_DIR="$(mktemp -d)"
trap 'rm -rf "$TEST_DIR"' EXIT

FAKE_GH="${TEST_DIR}/gh"
LOG_FILE="${TEST_DIR}/mutations.log"

cat > "$FAKE_GH" <<'EOF'
#!/usr/bin/env bash
set -euo pipefail

args="$*"
scenario="${FAKE_SCENARIO:-programmers}"

case "$args" in
  "auth status") exit 0 ;;
  "api user --jq .login") printf 'tester\n' ;;
  "api repos/tester/algo-study --jq .parent.full_name // \"\"") printf 'algo-gongbu/algo-study\n' ;;
  "api repos/algo-gongbu/algo-study/compare/main...tester:main --jq .ahead_by")
    if [ "$scenario" = "ahead" ]; then printf '2\n'; else printf '1\n'; fi
    ;;
  "api repos/algo-gongbu/algo-study/compare/main...tester:main --jq .behind_by") printf '0\n' ;;
  "api repos/algo-gongbu/algo-study/compare/main...tester:main --jq .files[].filename")
    case "$scenario" in
      ahead) printf 'tester/프로그래머스/1/42840. 모의고사/README.md\n' ;;
      baekjoon)
        printf 'tester/백준/Silver/11047. 동전 0/README.md\n'
        printf 'tester/백준/Silver/11047. 동전 0/동전 0.py\n'
        ;;
      multiple)
        printf 'tester/백준/Silver/11047. 동전 0/README.md\n'
        printf 'tester/백준/Gold/9935. 문자열 폭발/README.md\n'
        ;;
      programmers)
        printf 'tester/프로그래머스/1/42840. 모의고사/README.md\n'
        printf 'tester/프로그래머스/1/42840. 모의고사/모의고사.py\n'
        ;;
    esac
    ;;
  "run list --repo tester/algo-study --workflow auto-move.yml --limit 1 --json databaseId,status,conclusion,url,headSha --jq .[0] | [.databaseId, .status, (.conclusion // \"\"), .url, .headSha] | @tsv")
    printf '123\tcompleted\tsuccess\thttps://github.test/run/123\tbefore-auto-move\n'
    ;;
  "api repos/tester/algo-study/actions/variables/BAEKJOON_ID --jq .value") printf 'tester\n' ;;
  "api repos/tester/algo-study/commits/main --jq .sha") printf 'fork-head-sha\n' ;;
  api\ --method\ POST\ repos/tester/algo-study/git/refs*)
    printf '%s\n' "$args" >> "${FAKE_LOG_FILE:?}"
    ;;
  api\ --method\ POST\ repos/algo-gongbu/algo-study/pulls*)
    printf '%s\n' "$args" >> "${FAKE_LOG_FILE:?}"
    printf '1070\thttps://github.test/algo-gongbu/algo-study/pull/1070\n'
    ;;
  *)
    printf '%s\n' "$args" >> "${FAKE_LOG_FILE:?}"
    ;;
esac
EOF
chmod +x "$FAKE_GH"

run_cli() {
  FAKE_SCENARIO="$1" \
  FAKE_LOG_FILE="$LOG_FILE" \
  STUDY_GH_BIN="$FAKE_GH" \
  "$CLI" "${@:2}"
}

assert_contains() {
  local output="$1"
  local expected="$2"
  [[ "$output" == *"$expected"* ]] || {
    printf '기대 문자열을 찾지 못했습니다: %s\n출력:\n%s\n' "$expected" "$output" >&2
    exit 1
  }
}

test_start_protects_unsubmitted_changes() {
  : > "$LOG_FILE"
  local output status
  set +e
  output="$(run_cli ahead start 2>&1)"
  status=$?
  set -e
  [ "$status" -ne 0 ]
  assert_contains "$output" "미제출 풀이일 수 있어 동기화를 중단했습니다"
  [ ! -s "$LOG_FILE" ]
}

test_submit_dry_run_detects_programmers_problem() {
  : > "$LOG_FILE"
  local output
  output="$(run_cli programmers submit --dry-run --note '완전탐색')"
  assert_contains "$output" "tester/프로그래머스/1/42840. 모의고사"
  assert_contains "$output" "tester:pro/level1/42840"
  assert_contains "$output" "PR 제목: Pro/level1/42840"
  assert_contains "$output" "원본 저장소는 변경하지 않았습니다"
  [ ! -s "$LOG_FILE" ]
}

test_submit_rejects_multiple_problems() {
  : > "$LOG_FILE"
  local output status
  set +e
  output="$(run_cli multiple submit --dry-run 2>&1)"
  status=$?
  set -e
  [ "$status" -ne 0 ]
  assert_contains "$output" "두 개 이상의 문제 변경이 감지됐습니다"
  [ ! -s "$LOG_FILE" ]
}

test_submit_creates_and_merges_baekjoon_pr() {
  : > "$LOG_FILE"
  local output mutations
  output="$(run_cli baekjoon submit --note '그리디')"
  mutations="$(cat "$LOG_FILE")"

  assert_contains "$output" "tester/백준/Silver/11047. 동전 0"
  assert_contains "$output" "PR 생성 완료: https://github.test/algo-gongbu/algo-study/pull/1070"
  assert_contains "$output" "Merge commit 완료"
  assert_contains "$output" "fork 재동기화 완료"
  assert_contains "$mutations" "ref=refs/heads/boj/Silver/11047"
  assert_contains "$mutations" "title=Boj/silver/11047"
  assert_contains "$mutations" "pr merge 1070 --repo algo-gongbu/algo-study --merge --delete-branch --match-head-commit fork-head-sha"
  assert_contains "$mutations" "repo sync tester/algo-study --source algo-gongbu/algo-study --branch main --force"
}

bash -n "$CLI"
test_start_protects_unsubmitted_changes
test_submit_dry_run_detects_programmers_problem
test_submit_rejects_multiple_problems
test_submit_creates_and_merges_baekjoon_pr
printf 'study CLI tests passed\n'
