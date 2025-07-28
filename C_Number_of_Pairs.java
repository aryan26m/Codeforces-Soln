import java.util.Scanner;
import java.util.Arrays;

public class C_Number_of_Pairs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long l = sc.nextLong();
            long r = sc.nextLong();
            long[] a = enterArray(n, sc);
            Arrays.sort(a);

            long cnt1 = 0;
            long cnt2 = 0;

            int i = 0;
            int q = n - 1;
            while (i < q) {
                if (a[i] + a[q] <= r) {
                    cnt1 += q - i;
                    i++;
                } else {
                    q--;
                }
            }

            int j = 0;
            int p = n - 1;
            while (j < p) {
                if (a[j] + a[p] <= (l - 1)) {
                    cnt2 += p - j;
                    j++;
                } else {
                    p--;
                }
            }

            long rem = cnt1 - cnt2;
            System.out.println(rem);
        }
        sc.close();
    }

    private static long[] enterArray(int size, Scanner sc) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++) {
            array[i] = sc.nextLong();
        }
        return array;
    }
}
