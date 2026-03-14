import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            int N = sc.nextInt();
            int[] line = new int[N]; 
            

            for (int i = 1; i <= N; i++) {
                int leftCount = sc.nextInt(); 
                int emptyCount = 0; 
                

                for (int j = 0; j < N; j++) {

                    if (emptyCount == leftCount && line[j] == 0) {
                        line[j] = i;
                        break; 
                    }
                    
                    // 빈칸을 만날 때마다 카운트 증가
                    if (line[j] == 0) {
                        emptyCount++;
                    }
                }
            }
            

            for (int i = 0; i < N; i++) {
                System.out.print(line[i] + " ");
            }
        }
        
        sc.close();
    }
}