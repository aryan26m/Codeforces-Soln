import java.util.Scanner;

public class Convert_string {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n = sc.nextInt();
            sc.nextLine(); // Consume the newline character

            String s = sc.nextLine();
            int cntZero = 0;
            int cntOne = 0;

            // Count zeroes and ones
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '0') {
                    cntZero++;
                } else {
                    cntOne++;
                }
            }

            int validCount = 0;

            // Check all k from 1 to N
            for (int k = 1; k <= n; k++) {
                if (cntZero % k == 0 || cntOne % k == 0) {
                    validCount++;
                }
            }

            System.out.println(validCount);
        }
        sc.close();
    }
}
