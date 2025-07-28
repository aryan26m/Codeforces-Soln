import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class F_Ira_and_Flamenco {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            HashMap<Integer, Integer> hm = new HashMap<>();
            for (int x : a) {
                hm.put(x, hm.getOrDefault(x, 0) + 1);
            }

            long ans = 0;
            int mod = 1000000007;
            HashSet<Integer> hs = new HashSet<>();
            for (int x : a) {
                hs.add(x);
            }

            long sum = 1;
            Integer[] hsar = hs.toArray(new Integer[hs.size()]);
            Arrays.sort(hsar);

            if (hsar.length >= m) {
                for (int i = 0; i < m; i++) {
                    sum = (sum * hm.get(hsar[i])) % mod;
                }
                if (hsar[m - 1] - hsar[0] < m) {
                    ans = sum;
                }
            }

            for (int i = m; i < hsar.length; i++) {
                sum = (sum * hm.get(hsar[i])) % mod;
                sum = sum * modInverse(hm.get(hsar[i - m]), mod) % mod;

                if ((hsar[i] - hsar[i - m + 1]) < m) {
                    ans = (ans + sum) % mod;
                }
            }

            System.out.println(ans);
        }
    }

    public static long modInverse(long a, long mod) {
        return power(a, mod - 2, mod);
    }

    public static long power(long x, long y, long mod) {
        long res = 1;
        x = x % mod;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % mod;
            }
            y = y >> 1;
            x = (x * x) % mod;
        }
        return res;
    }
}
