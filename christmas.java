import java.util.Scanner;

public class christmas {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] fact = new long[n + 1];
        long mod = 1000000007;
        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        long ans = 0;
        long sign = 1;

        for (int i = 2; i <= n; i++) {
            long modinv = pow(fact[i], mod - 2, mod);
            long sum = (fact[n] * modinv) % mod;
            // System.out.println(sum);
            if (sign == 1) {
                ans = (ans + sum) % mod;
            } else {
                ans = (ans - sum + mod) % mod;
            }
            sign *= -1;
        }

        System.out.println(ans);
        sc.close();
    }

    public static long pow(long a, long b, long mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) != 0) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
}
