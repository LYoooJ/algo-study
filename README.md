
# 📚 Algo Gongbu Study

## 📊 Weekly Dashboard

<!-- WEEKLY_DASHBOARD_START -->

📅 기준: 2026-02-09 (월요일 00:00 KST)

| Member | Count | Status |
|--------|-------|--------|
| FaceWithNull | 8 | ✅ |
| tomchaccom | 4 | ❌ |
<!-- WEEKLY_DASHBOARD_END -->



# 스터디 참여 가이드

스터디 참여는 아래 순서대로 진행해주세요.

---

## 1. 공용 스터디 레포 Fork 하기

1. 공용 스터디 레포에 접속합니다.
2. 우측 상단의 **Fork** 버튼을 클릭합니다.
3. `Choose an owner`에서 본인 계정을 선택합니다.

반드시 본인 계정으로 fork 해야 합니다.

<img width="1315" height="527" alt="image" src="https://github.com/user-attachments/assets/f32802dd-189c-47df-82ac-16353143d7e1" />
<img width="764" height="577" alt="image" src="https://github.com/user-attachments/assets/ee283224-7ca0-4556-b44b-b479027df96b" />

---

## 2. Repository Variable 설정 (BAEKJOON_ID)

Action이 실행될 때 본인 폴더로 자동 이동하기 위해 반드시 설정해야 합니다.

### 2-1. fork한 레포의 Settings로 이동

<img width="657" height="484" alt="image" src="https://github.com/user-attachments/assets/d0d44a28-e661-4414-bd17-0d5ed0c6ca6a" />

### 2-2. Security → Secrets and variables → Actions

<img width="176" height="177" alt="image" src="https://github.com/user-attachments/assets/80de399b-67e3-4d4e-9877-2c38f34901b9" />

### 2-3. Variable 추가

- **Name:** `BAEKJOON_ID`
- **Value:** 본인의 백준 아이디

공용 레포에 생성된 본인 디렉토리명과 반드시 동일해야 합니다.

<img width="708" height="358" alt="image" src="https://github.com/user-attachments/assets/444572ae-30e4-424b-80c8-e3045c4f3682" />

---

## 3. 백준 문제 풀이 후 Action 확인

1. 백준에서 문제를 풉니다.
2. 제출이 완료되면 BaekjoonHub가 fork 레포의 `main` 브랜치에 자동 업로드합니다.
3. fork 레포의 **Actions** 탭으로 이동합니다.
4. `move`라는 이름의 workflow가 정상 실행되었는지 확인합니다.

<img width="729" height="578" alt="image" src="https://github.com/user-attachments/assets/c74ddb8e-5c26-4255-a6c5-aab986de2627" />

---

## 4. main 기준 브랜치 생성

Action이 정상 실행되었다면, 본인 백준 아이디 폴더 내부에 방금 푼 문제가 등록되어 있습니다.

이제 PR을 위해 브랜치를 생성합니다.

### 브랜치 컨벤션

```
/boj/{문제티어}/{문제번호}
```

예시:

```
/boj/Gold/9935
/boj/Silver/1926
```

<img width="309" height="244" alt="image" src="https://github.com/user-attachments/assets/ff5fd580-d0db-49d1-b757-606802f4781d" />

---

## 5. 공용 스터디 레포에 PR 생성

1. 생성한 브랜치를 push 합니다.
2. `Compare & pull request` 버튼을 클릭합니다.
3. Base repository가 공용 스터디 레포인지 확인합니다.
4. PR을 생성합니다.

<img width="671" height="166" alt="image" src="https://github.com/user-attachments/assets/bb632b61-2692-48e4-8dc5-22dc5d6f179f" />

---

## 6. main으로 Squash Merge

코드 확인 후 **Squash and merge**를 진행합니다.

반드시 Squash Merge를 사용합니다.

<img width="703" height="57" alt="image" src="https://github.com/user-attachments/assets/196da5ab-e6bf-446e-a136-ab4de22870f1" />



