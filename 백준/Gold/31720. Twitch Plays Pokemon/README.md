# [Gold III] Twitch Plays Pokemon - 31720 

[문제 링크](https://www.acmicpc.net/problem/31720) 

### 성능 요약

메모리: 5340 KB, 시간: 132 ms

### 분류

너비 우선 탐색, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색

### 제출 일자

2026년 3월 29일 20:47:08

### 문제 설명

<p>Twitch Plays Pokemon은 생방송 플랫폼 Twitch에서 유행했던 콘텐츠이다. 시청자가 채팅으로 명령을 입력하면 그 명령이 게임에 반영되어 게임 속 캐릭터를 조종한다. 수많은 시청자가 동시에 채팅을 치기 때문에 채팅 순서가 꼬여서 원하는 대로 캐릭터를 조종하기 힘들지만, 그게 바로 Twitch Plays Pokemon 콘텐츠의 매력이다.</p>

<p>게임은 $N\times N$ 격자 미로에서 진행된다. 격자의 각 칸은 빈칸 또는 벽이다. 캐릭터는 빈칸에서 시작하며, 다른 빈칸에 있는 목적지까지 도달해야 한다. 시청자가 입력할 수 있는 명령은 <span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>D</code></span>, <span style="color:#e74c3c;"><code>L</code></span>, <span style="color:#e74c3c;"><code>R</code></span> 중 하나로, 각각 캐릭터를 위, 아래, 왼쪽, 오른쪽으로 한 칸 이동하라는 명령이다. 벽 또는 미로 밖을 향해 이동하라는 명령이 주어진 경우 캐릭터는 움직이지 않는다. 캐릭터가 목적지에 도달하는 즉시 미로를 탈출하며, 더 이상 명령에 따라 이동하지 않는다.</p>

<p>어느 날 새벽, 달구와 포닉스가 Twitch Plays Pokemon 게임에 참여했다. 두 시청자는 합심해서 게임 속 미로를 탈출하는 데 성공했다! 그런데 안타깝게도 그 역사적인 순간을 기록해 둔 사람은 아무도 없었다. 방송 진행자 윤이는 각 시청자의 채팅 기록을 시간 순서대로 확인하는 것이 가능하지만, 두 시청자의 채팅 간 순서를 알 수는 없었다.</p>

<p>달구와 포닉스의 채팅을 적절한 순서로 배열했을 때, 최소 몇 번의 명령 만에 캐릭터가 미로를 탈출했을지 구하시오.</p>

### 입력 

 <p>첫째 줄에 미로의 크기를 나타내는 정수 $N$이 주어진다. $(2\le N\le 20)$</p>

<p>둘째 줄부터 $N$개의 줄에 미로를 나타내는 길이 $N$의 문자열이 주어진다. 각 문자가 나타내는 의미는 다음과 같다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>.</code></span>: 빈칸</li>
	<li><span style="color:#e74c3c;"><code>#</code></span>: 벽</li>
	<li><span style="color:#e74c3c;"><code>S</code></span>: 캐릭터가 시작하는 지점 (미로에 하나만 주어진다.)</li>
	<li><span style="color:#e74c3c;"><code>E</code></span>: 캐릭터가 도달해야 하는 지점 (미로에 하나만 주어진다.)</li>
</ul>

<p>다음 줄에 달구가 입력한 명령이 채팅을 친 순서대로 주어진다.</p>

<p>다음 줄에 포닉스가 입력한 명령이 채팅을 친 순서대로 주어진다.</p>

<p>달구와 포닉스가 입력한 명령은 각각 길이 $1$ 이상 $100$ 이하의 문자열로 주어지며, 문자 <span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>D</code></span>, <span style="color:#e74c3c;"><code>L</code></span>, <span style="color:#e74c3c;"><code>R</code></span>로 구성된다.</p>

### 출력 

 <p>달구와 포닉스의 채팅을 적절한 순서로 배열했을 때, 최소 몇 번의 명령 만에 캐릭터가 미로를 탈출했을지를 출력한다.</p>

<p>만약 (전산 오류 등의 이유로) 채팅을 어떻게 배열해도 캐릭터가 미로를 탈출할 수 없다면, 대신 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

