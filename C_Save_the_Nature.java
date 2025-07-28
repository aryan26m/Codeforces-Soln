import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class C_Save_the_Nature {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        long t = nextLong();
        while (t-- > 0) {
            long n = nextLong();
            long arr[] = enterArr((int) n);
            long x = nextLong();
            long a = nextLong();
            long y = nextLong();
            long b = nextLong();
            long k = nextLong();
            long l = 0;
            long h = n;
            if (y > x) {
                long temp = y; y = x; x = temp; temp = a; a = b; b = temp;
            }
            Arrays.sort(arr);
            long ans = -1;
            while (l <= h) {
                long m = (l + h) / 2;
                long lcm = findLCM(a, b);
                long a1 = m / lcm;
                long a2 = (m / a) - a1;
                long a3 = (m / b) - a1;
                long i = n - 1;
                long money = 0;
                while (a1 > 0) {
                    money += (arr[(int) i--] / 100) * (x + y);
                    a1--;
                }
                while (a2 > 0) {
                    money += (arr[(int) i--] / 100) * x;
                    a2--;
                }
                while (a3 > 0) {
                    money += (arr[(int) i--] / 100) * y;
                    a3--;
                }
                if (money >= k) {
                    ans = m;
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            System.out.println(ans);
        }
    }

    public static long[] enterArr(int n) throws IOException {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextLong();
        }
        return arr;
    }

    public static long findLCM(long a, long b) {
        return (a * b) / findGCD(a, b);
    }

    public static long findGCD(long a, long b) {
        if (b == 0) {
            return a;
        }
        return findGCD(b, a % b);
    }

    public static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}
