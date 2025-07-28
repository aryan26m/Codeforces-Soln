import java.util.Scanner;
import java.util.Arrays;

public class C_Set_or_Decrease {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        while (t-- > 0) {
            long n = sc.nextLong();
            long k = sc.nextLong();
            long a[] = enterarr(n,sc);
            Arrays.sort(a);
            long sum = 0;
            for (long p : a) {
                sum += p;
            }
            long l = 0;
            long h = (long) 1e10;
            long ans = 0;
            while (l <= h) {
                long m = (l + h) / 2;
                if (solve(a, m, k, sum)) {
                    ans = m;
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }

    public static boolean solve(long a[], long m, long k, long sum) {
        if ((sum - m) <= k) {
            return true;
        }
        long n = a.length;
        for (long i = n - 1; i >= Math.max(1, n - m); i--) {
            sum -= a[(int) i];
            long oprnlft = m - (n - i);
            long remsum = sum - a[0] + (n - i + 1) * (a[0] - oprnlft);
            if (remsum <= k) {
                return true;
            }
        }
        return false;
    }

    public static long[] enterarr(long n,Scanner sc) {
        // Scanner sc = new Scanner(System.in);
        long[] arr = new long[(int) n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        return arr;
    }
}
