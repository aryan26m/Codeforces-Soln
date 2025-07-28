import java.util.Scanner;

public class CLetters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] a = enterArray(n, sc);
        long l = 0;
        long h = Long.MAX_VALUE;
        long ans = Long.MAX_VALUE;

        while (l <= h) {
            long mid = (l + h) / 2;
            if (possible(mid, k, a)) {
                ans = Math.min(ans, mid);
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        System.out.println(ans);
        sc.close();
    }

    public static boolean possible(long x, int k, long[] a) {
        int worker = 1;
        long work = 0;
        for (long w : a) {
            if (work + w <= x) {
                work += w;
            } else {
                if (worker == k) {
                    return false;
                }
                if (w > x) {
                    return false;
                }
                worker++;
                work = w;
            }
        }
        return true;
    }

    private static long[] enterArray(int size, Scanner sc) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++) {
            array[i] = sc.nextLong();
        }
        return array;
    }
}
