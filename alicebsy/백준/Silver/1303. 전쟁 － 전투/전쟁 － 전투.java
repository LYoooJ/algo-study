import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int N, M;
    static char[][] grid;
    static boolean[][] visited;
    // 상하좌우 탐색을 위한 방향 배열
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            N = sc.nextInt(); // 열
            M = sc.nextInt(); // 행
            
            grid = new char[M][N];
            visited = new boolean[M][N];
            
            for (int i = 0; i < M; i++) {
                String line = sc.next();
                grid[i] = line.toCharArray();
            }
            
            long powerW = 0; // 흰색
            long powerB = 0; // 파란색
            
            // 모든 칸을 돌면서 방문하지 않은 병사를 찾으면 탐색 시작
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (!visited[i][j]) {
                        // BFS를 통해 연결된 병사 수 카운트
                        long count = bfs(i, j, grid[i][j]);
                        
                        // 제곱 누적
                        if (grid[i][j] == 'W') {
                            powerW += (count * count);
                        } else {
                            powerB += (count * count);
                        }
                    }
                }
            }
            
            // 정답
            System.out.println(powerW + " " + powerB);
        }
        sc.close();
    }

    // BFS 탐색 메서드
    static long bfs(int x, int y, char team) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y});
        visited[x][y] = true;
        
        long count = 1; 
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];
            
            // 상하좌우
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                // 전장 범위를 벗어나지 않고
                if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                    // 아직 방문하지 않았으며, 같은 팀인 경우
                    if (!visited[nx][ny] && grid[nx][ny] == team) {
                        visited[nx][ny] = true; // 방문
                        queue.offer(new int[]{nx, ny});
                        count++; 
                    }
                }
            }
        }
        
        return count;
    }
}