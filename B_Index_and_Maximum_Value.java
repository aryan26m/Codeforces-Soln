import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;


public class B_Index_and_Maximum_Value {
    static Scanner sc = new Scanner(System.in); // Declare Scanner as static

    public static int[] enterarr(int N) {
        int[] arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = sc.nextInt();
        return arr;
    }

    public static void printarr(int[] arr) {
        // For debugging only
        for (int x : arr)
            System.out.print(x + " ");
        System.out.println();
    }

    public static boolean isPrime(long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        long sqrtN = (long) Math.sqrt(n) + 1;
        for (long i = 6L; i <= sqrtN; i += 6) {
            if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
        }
        return true;
    }

    public static long gcd(long a, long b) {
        if (a > b)
            a = (a + b) - (b = a);
        if (a == 0L)
            return b;
        return gcd(b % a, a);
    }

    public static int[] sort(int[] arr) {
        ArrayList<Integer> ls = new ArrayList<>();
        for (int x : arr)
            ls.add(x);
        Collections.sort(ls);
        for (int i = 0; i < arr.length; i++)
            arr[i] = ls.get(i);
        return arr;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
    
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            long[] arr = new long[n];
    
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Long.parseLong(st.nextToken());
            }
            long max = 0;
            for (int i = 0; i < n; i++) {
                max = Math.max(max, arr[i]);
            }
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                char op = st.nextToken().charAt(0);
                int l = Integer.parseInt(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
                if (max <= r && max >= l) {
                    if (op == '+') {
                        max = max + 1;
                    } else {
                        max = max - 1;
                    }
                }
                System.out.print(max + " ");
            }
            System.out.println();
        }
    }
    
}
