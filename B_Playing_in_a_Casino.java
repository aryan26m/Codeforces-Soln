import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B_Playing_in_a_Casino {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            ArrayList<ArrayList<Integer>> ar = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                ar.add(new ArrayList<>());
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ar.get(j).add(sc.nextInt());
                }
            }

            BigInteger ans = BigInteger.ZERO;
            for (ArrayList<Integer> x : ar) {
                Collections.sort(x);
                BigInteger[] suffix = new BigInteger[n];
                suffix[n - 1] = BigInteger.valueOf(x.get(n - 1));
                for (int i = n - 2; i >= 0; i--) {
                    suffix[i] = BigInteger.valueOf(x.get(i)).add(suffix[i + 1]);
                }

                for (int i = 0; i < n - 1; i++) {
                    BigInteger diff = suffix[i + 1].subtract(BigInteger.valueOf(n - i - 1).multiply(BigInteger.valueOf(x.get(i))));
                    ans = ans.add(diff);
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}