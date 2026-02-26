
# 📚 Algo Gongbu Study
## 📊 Weekly Dashboard

<!-- WEEKLY_DASHBOARD_START -->

📅 기준: 2026-02-23 (월요일 00:00 KST)

| Member | Count | Status |
|--------|-------|--------|
| - | 0 | ❌ |
<!-- WEEKLY_DASHBOARD_END -->



# 스터디 참여 가이드

스터디 참여는 아래 순서대로 진행해주세요.

---




## 1. 공용 스터디 레포 Fork 하기

1. 공용 스터디 레포에 접속합니다.
2. 우측 상단의 **Fork** 버튼을 클릭합니다.
3. `Choose an owner`에서 본인 계정을 선택합니다.

반드시 본인 계정으로 fork 해야 합니다.

<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/f32802dd-189c-47df-82ac-16353143d7e1" />
<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/ee283224-7ca0-4556-b44b-b479027df96b" />

---

## 2. 백준 허브가 설치되어 있다는 가정하에 진행합니다! 
1. 백준 허브 설치하기
2. github로 로그인하기
3. 첫번째 단계에서 fork 한 레포랑 연결하기!
   
### 브라우저 상단에서 설치한 백준 허브 클릭하기
<img width="360" height="270" alt="image" src="https://github.com/user-attachments/assets/0c102ca9-1a64-4f39-b182-2e1f2cecbb76" />

### 오른쪽 아래에 집 모양 클릭하기 

<img width="360" height="270" alt="image" src="https://github.com/user-attachments/assets/988621ad-b470-441f-9f43-4e7029ae126e" />

### fork 한 레포지터리명 입력하기 

<img width="360" height="270" alt="image" src="https://github.com/user-attachments/assets/283e1ab4-aa45-4b26-9a83-c1058e40df4c" />

### 아래처럼 나오면 성공

<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/6c0507e3-69b2-4922-ad47-748173c9a69b" />

### 깃에서 이런거 떠도 그냥 초록색 버튼 누르고 넘어가면 됩니다

<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/8421ac57-9a26-4328-a7be-b0f84d2a58c4" />


---

## 3. Repository Variable 설정 (BAEKJOON_ID)

Action이 실행될 때 본인 폴더로 자동 이동하기 위해 반드시 설정해야 합니다.

### 3-1. fork한 레포의 Settings로 이동

<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/d0d44a28-e661-4414-bd17-0d5ed0c6ca6a" />

### 3-2. Security → Secrets and variables → Actions

<img width="176" height="177" alt="image" src="https://github.com/user-attachments/assets/80de399b-67e3-4d4e-9877-2c38f34901b9" />

### 3-3. Variable 추가

- **Name:** `BAEKJOON_ID`

공용 레포에 생성된 본인 디렉토리명과 반드시 동일해야 합니다.

<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/444572ae-30e4-424b-80c8-e3045c4f3682" />

---

## 4. 백준 문제 풀이 후 Action 확인

1. 백준에서 문제를 풉니다.
2. 제출이 완료되면 BaekjoonHub가 fork 레포의 `main` 브랜치에 자동 업로드합니다.
3. fork 레포의 **Actions** 탭으로 이동합니다.
4. `move`라는 이름의 workflow가 정상 실행되었는지 확인합니다.

### ❗️❗️❗️ 주의점이 있습니다! 
- 레포에 현재 PR을 통한 Merge 시 리드미에 사용자별로 일주일에 몇번 PR을 넣었는지 동작하는 로직이 있습니다!
- 그래서 다른 사람이 먼저 main에 push 한 경우 여러분이 동기화한 시점에서 달라지는 부분이 생겨서 충돌이 발생합니다!
- 반드시 문제를 제출하기 직전에 동기화를 진행해 주세요!!!!

#### sync_fork 클릭 후 discard commit 을 선택해 주세요!(문제 제출 전에 해야 합니다.. 안그러면 백준 허브 재연결 해야해요..)
<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/5fa6dd12-f1fb-4c49-bfd0-be905ecb43dc" />

<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/c74ddb8e-5c26-4255-a6c5-aab986de2627" />

---

## 5. main 기준 브랜치 생성

Action이 정상 실행되었다면, 본인 백준 아이디 폴더 내부에 방금 푼 문제가 등록되어 있습니다.

이제 PR을 위해 브랜치를 생성합니다.

### 브랜치 컨벤션

```
/boj/{문제티어}/{문제번호}
```
```
/pro/문제레벨
> 프로그래머스 문제는 한국어로 구성되어 있어서 PR에 자세한 내용을 첨부 부탁드립니다!
```

예시:

```
/boj/Gold/9935
/boj/Silver/1926
```

<img width="360" height="270" alt="image" src="https://github.com/user-attachments/assets/ff5fd580-d0db-49d1-b757-606802f4781d" />

---

## 6. 공용 스터디 레포에 PR 생성

1. 생성한 브랜치를 push 합니다.
2. `Compare & pull request` 버튼을 클릭합니다.
3. Base repository가 공용 스터디 레포인지 확인합니다.
4. PR을 생성합니다.

<img width="671" height="166" alt="image" src="https://github.com/user-attachments/assets/bb632b61-2692-48e4-8dc5-22dc5d6f179f" />

---

## 7. main으로 Squash Merge

코드 확인 후 **Squash and merge**를 진행합니다.

반드시 Squash Merge를 사용합니다.

<img width="703" height="57" alt="image" src="https://github.com/user-attachments/assets/196da5ab-e6bf-446e-a136-ab4de22870f1" />


---
## 8. fork 된 레포지터리와 메인 레포를 동기화하기
- squash merge로 인해, 공용 스터디 레포의 커밋 히스토리와, 현재 본인의 레포간 동기화가 제대로 되어었지 않을 겁니다!
- 그래서 sync_fork 클릭 후 discard commit 을 선택해 주세요!

### discard commit 으로 동기화(동기화 진행 없이 PR을 보내면 기존 커밋 내역도 PR에 같이 들어갑니다)
<img width="720" height="540" alt="image" src="https://github.com/user-attachments/assets/5fa6dd12-f1fb-4c49-bfd0-be905ecb43dc" />

### 동기화 완료 
<img width="900" height="270" alt="image" src="https://github.com/user-attachments/assets/42e0cef1-cfd9-4a50-a40d-94256e4cc787" />












