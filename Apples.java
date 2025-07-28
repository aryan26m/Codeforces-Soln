import java.util.Scanner;

public class Apples {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int  m=sc.nextInt();

        long[] fact = new long[n+1];
        long mod = 1000000007;
        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        long ans = 0;
        long fact1=fact[n+m-1];
        long fact2=(fact1*pow(fact[n-1], mod-2, mod)%mod);
        ans=(fact2*pow(fact[m], mod-2, mod)%mod);

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
