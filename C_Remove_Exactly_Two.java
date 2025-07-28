import java.io.*;
import java.util.*;

public class C_Remove_Exactly_Two {
    static final int MOD = 1000000007;
    static final int MAX = 100000;
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final PrintWriter pw = new PrintWriter(System.out);
    
    static class FastIO {
        StringTokenizer st;
        
        String next() throws IOException {
            while (st == null || !st.hasMoreElements()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }
        
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
    
    static void addEdge(List<Integer>[] tree, int u, int v) {
        tree[u].add(v);
        tree[v].add(u);
    }

    static void solve() throws IOException {
        FastIO io = new FastIO();
        int n = io.nextInt();
        List<Integer>[] list = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            list[i] = new ArrayList<>();
        }
        int[] degree = new int[n + 1];

        for (int i = 0; i < n - 1; i++) {
            int u = io.nextInt();
            int v = io.nextInt();
            addEdge(list, u, v);
            degree[u]++;
            degree[v]++;
        }

        if (n <= 2) {
            pw.println(0);
            return;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> degree[b] - degree[a]);
        for (int i = 1; i <= n; i++) {
            pq.add(i);
        }

        int maxComponents = 0;
        List<Integer> topCandidates = new ArrayList<>();
        for (int i = 0; i < Math.min(300, n); i++) {
            topCandidates.add(pq.poll());
        }

        for (int i = 0; i < topCandidates.size(); i++) {
            for (int j = i + 1; j < topCandidates.size(); j++) {
                int u = topCandidates.get(i);
                int v = topCandidates.get(j);
                boolean adjacent = list[u].contains(v);

                int components = degree[u] + degree[v] - (adjacent ? 2 : 1);
                maxComponents = Math.max(maxComponents, components);
            }
        }

        maxComponents = Math.min(maxComponents, n - 2);
        pw.println(maxComponents);
    }

    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int t = io.nextInt();
        while (t-- > 0) {
            solve();
        }
        pw.flush();
    }
}
