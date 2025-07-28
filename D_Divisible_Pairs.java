import java.io.*;
import java.util.*;

public class D_Divisible_Pairs {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());

            long[] a = new long[n];
            long[] b = new long[n];
            HashMap<Long, HashSet<Integer>> hm = new HashMap<>();

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st.nextToken());
                b[i] = a[i] % x;

                hm.computeIfAbsent(b[i], k -> new HashSet<>()).add(i);
            }

            long ans = 0;
            for (int i = 0; i < n; i++) {
                long req = (b[i] == 0) ? 0 : x - b[i];

                if (hm.containsKey(req)) {
                    for (int p : hm.get(req)) {
                        if (i < p && Math.abs(a[i] - a[p]) % y == 0) {
                            ans++;
                        }
                    }
                }
            }

            pw.println(ans);
        }
        pw.flush();
        pw.close();
    }
}