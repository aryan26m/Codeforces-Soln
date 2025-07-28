import java.util.Arrays;
import java.util.Scanner;

public class E_Kevin_and_And {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int k = scanner.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt(); 
            }

            int[] b = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt(); 
            }

            int[] minA = new int[n];
            for (int i = 0; i < n; i++) {
                minA[i] = a[i];
                for (int j = 0; j < m; j++) {
                    minA[i] = Math.min(minA[i], a[i] & b[j]);
                }
            }

            Arrays.sort(a);
            Arrays.sort(minA);

            for (int i = 0; i < Math.min(k, n); i++) {
                a[n - 1 - i] = minA[i];
               }

             long sum = 0;
            for (int value : a) {
                sum += value;
            }
     System.out.println(sum);
        }

        scanner.close();
    }
}