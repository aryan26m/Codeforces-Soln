import java.util.*;

public class G_1_Teleporters_Easy_Version {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int c = sc.nextInt();
            int ans = 0;
            int[] a = new int[n + 5];
            int[] sum = new int[n + 5];
            Arrays.fill(sum, 0);
            for (int i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
                sum[i] = a[i] + i;
            }
            Arrays.sort(sum, 1, n + 1);
            int ind = 1;
            while (c - sum[ind] >= 0) {
                if (ind > n) break;
                c -= sum[ind];
                ind++;
                ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}
