import java.math.BigInteger;
import java.util.Scanner;

public class D_Almost_Identity_Permutations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        BigInteger[] fact = new BigInteger[n + 1];
        fact[0] = BigInteger.ONE;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
        }

        BigInteger ans = BigInteger.ONE;

        for (int i = 2; i <= k; i++) {
            BigInteger nfact = fact[n];
            BigInteger res = BigInteger.ZERO;
            BigInteger kfact = fact[i];
            BigInteger nkfact = fact[n - i];
            BigInteger parity = BigInteger.ONE;

            for (int j = 2; j <= i; j++) {
                res = res.add(fact[i].divide(fact[j]).multiply(parity));
                parity = parity.negate();
            }

            BigInteger ncr = nfact.divide(kfact).divide(nkfact);
            ans = ans.add(ncr.multiply(res));
        }
        System.out.println(ans);
    }
}
