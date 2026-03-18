import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNext()) {
            String S = sc.next();
            int len = S.length();
            
            for (int i = 0; i < len; i++) {
                if (isPalindrome(S.substring(i))) {
                    System.out.println(len + i);
                    break;
                }
            }
        }
        
        sc.close();
    }
    
    static boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false; 
            }
            left++;
            right--;
        }
        return true; 
    }
}