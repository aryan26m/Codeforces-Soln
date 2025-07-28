import java.util.Scanner;

public class C_Ski_Resort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int q = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            long count = 0;
            for (int i = 0; i < n;) {
                if (arr[i] > q) {
                    i++;
                    continue;
                }
                int tcount = 0;
                while (i < n && arr[i] <= q) {
                    i++;
                    tcount++;
                }
                if (tcount >= k) {
                    long ab = (long) (tcount - k) + 1;
                    count += ((ab + 1) * ab) / 2;
                }
            }
            System.out.println(count);
        }
    }
}
