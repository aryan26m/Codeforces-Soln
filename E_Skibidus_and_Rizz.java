import java.util.Scanner;

public class E_Skibidus_and_Rizz {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        
        while (t-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int k = scanner.nextInt(); 
            
            if ((n+m)>k) {
                System.out.println(-1);
                continue;
            }
            
            StringBuilder result = new StringBuilder();
            
            for (int i = 0; i < k; i++) {
                result.append('0');
            }
            for (int i = 0; i < k; i++) {
                result.append('1');
            }
            
            n -= k;
            m -= k;
            
            while (n > 0 || m > 0) {
                if (m > 0) {
                    result.append('1');
                    m--;
                }
                if (n > 0) {
                    result.append('0');
                    n--;
                }
            }
            
            System.out.println(result.toString());
        }
        
        scanner.close();
    }
}
