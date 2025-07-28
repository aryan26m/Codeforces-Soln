import java.util.Scanner;

public class C_Letters {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        long[] a = enterArray(n, sc);
        long[] room = enterArray(r, sc);
        long rsf = 0;
        long idx = a[0];
        int j = 0;

        for (int i = 0; i < r; i++) {
            while (j < n && room[i] > idx) {
                rsf += a[j];
                j++;
                if (j < n) {
                    idx += a[j];
                }
            }
            System.out.println((j + 1) + " " + (room[i] - rsf));
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
