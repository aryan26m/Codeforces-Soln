import java.io.*;
import java.util.*;

public class B_Monsters {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            List<Pair> v = new ArrayList<>();
            
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (x % k == 0) {
                    System.out.print((i + 1) + " ");
                } else {
                    v.add(new Pair(x % k, i + 1));
                }
            }
            
            v.sort((a, b) -> b.first - a.first);
            
            for (Pair p : v) {
                System.out.print(p.second + " ");
            }
            System.out.println();
        }
    }
    
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
