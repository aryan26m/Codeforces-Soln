import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class factorydf {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());

        long[] a = new long[n];
        long max = Long.MAX_VALUE;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(st.nextToken());
            max = Math.min(max, a[i]);
        }

        long l = 0;
        long h = max * k;
        long ans = Long.MAX_VALUE;

        while (l <= h) {
            long mid = (l + h) / 2;
            if (predicate(mid, k, a)) {
                ans = Math.min(ans, mid);
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        System.out.println(ans);
    }

    public static boolean predicate(long mid, long k, long[] a) {
        long ans = 0;
        for (long x : a) {
            ans += (mid / x);
            if (ans >= k) {
                return true;
            }
        }
        return ans >= k;
    }
}
