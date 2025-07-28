import java.io.*;
import java.util.*;

public class E_Cardboard_for_Pictures {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static int n;
    static long c;
    static int[] v;

    public static boolean valid(long mid) {
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (v[i] + 2 * mid) * (v[i] + 2 * mid);
            if (sum > c)
                return false;
        }
        return sum <= c;
    }

    public static void solve() throws IOException {
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        c = Long.parseLong(input[1]);
        v = new int[n];
        String[] vInput = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(vInput[i]);
        }

        long l = 1, r = (long) Math.sqrt(c), mid;
        while (r - l > 1) {
            mid = (r + l) / 2;
            if (valid(mid))
                l = mid;
            else
                r = mid;
        }
        out.println(l);
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve();
        }
        out.flush();
    }
}
