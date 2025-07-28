import java.io.*;
import java.util.*;

public class B_Divan_and_a_New_Project {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(next());
        while (t-- > 0) {
            int n = Integer.parseInt(next());
            List<Pair> list = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                list.add(new Pair(Long.parseLong(next()), i));
            }

            Collections.sort(list, (a, b) -> Long.compare(b.value, a.value));

            HashMap<Integer, Integer> hm = new HashMap<>();
            int p1 = 0;
            int p2 = 2;

            for (int i = 0; i < n; i += 2) {
                hm.put(list.get(i).index, p1);
                p1 -= 1;
            }

            for (int i = 1; i < n; i += 2) {
                hm.put(list.get(i).index, p2);
                p2 += 1;
            }

            long ans = 0;
            int x = 0;

            for (int i = 0; i < n;) {
                x++;
                int cnt = 0;
                while (cnt < 2 && i < n) {
                    ans += list.get(i).value * x * 2;
                    cnt++;
                    i++;
                }
            }

            out.println(ans);
            out.print(1 + " ");
            for (int i = 0; i < n; i++) {
                out.print(hm.get(i) + " ");
            }
            out.println();
        }
        out.flush();
    }

    static class Pair {
        long value;
        int index;

        Pair(long value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
