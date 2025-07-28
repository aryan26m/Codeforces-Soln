import java.util.Scanner;

public class B_JoJo_s_Incredible_Adventures {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong(); // Changed int to long
        sc.nextLine();
        while(t-- > 0) {
            String s = sc.nextLine();
            long n = s.length(); // Changed int to long
            char ch[] = s.toCharArray();
            long st = 0;
            long e = 0;
            for(long i = 0; i < n; i++) { // Changed int to long
                if (ch[(int)i] == '1') {
                    st++;
                } else {
                    break;
                }
            }

            for(long i = n - 1; i >= 0; i--) { // Changed int to long
                if (ch[(int)i] == '1') {
                    e++;
                } else {
                    break;
                }
            }
            long adj = 0;
            long maxadj = 0;
            long zero = 0;
            for(long i = 0; i < n; i++) { // Changed int to long
                if (ch[(int)i] == '1') {
                    adj++;
                } else {
                    zero++;
                    adj = 0;
                }
                maxadj = Math.max(adj, maxadj);
            }
            maxadj = Math.max(adj, maxadj);
            maxadj = Math.max(maxadj, (st + e));
            long r = (maxadj - 1) / 2;
            long ans2 = (maxadj - r) * (r + 1);
            if (zero == 0) {
                long ans = n * n;
                System.out.println(ans);
            } else {
                System.out.println(ans2);
            }
        }
        sc.close();
    }
}
