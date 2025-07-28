import java.util.*;

public class E_Knapsack_on_a_Segment {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[] w = enterarr(n, sc);
        long[] c = enterarr(n, sc);
        long weight = 0;
        long cost = 0;
        long ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            weight += w[r];
            cost += c[r];
            while (weight > k) {
                weight -= w[l];
                cost -= c[l];
                l++;
            }
            ans = Math.max(ans, cost);
        }
        System.out.println(ans);
    }

    public static long[] enterarr(int n, Scanner sc) {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        return arr;
    }
}
