import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNext()) {
            String A = sc.next();
            String B = sc.next();
            
            int lenA = A.length();
            int lenB = B.length();
            
            int minLen = lenA + lenB; 
            
            for (int i = -lenB; i <= lenA; i++) {
                boolean isValid = true;
                
                for (int j = 0; j < lenA; j++) {
                    int k = j - i; 
                    
                    if (k >= 0 && k < lenB) {
                        if (A.charAt(j) == '2' && B.charAt(k) == '2') {
                            isValid = false;
                            break;
                        }
                    }
                }
                
                if (isValid) {
                    int start = Math.min(0, i);
                    int end = Math.max(lenA, i + lenB);
                    
                    minLen = Math.min(minLen, end - start);
                }
            }
            
            System.out.println(minLen);
        }
        
        sc.close();
    }
}