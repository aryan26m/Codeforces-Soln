import java.io.*;
import java.util.*;

public class MovieFestival {
    static class Pair {
        long x, y;
        Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Pair> pq = new PriorityQueue<>(n, Comparator.comparingLong(a -> a.y));
        
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            pq.add(new Pair(Long.parseLong(input[0]), Long.parseLong(input[1])));
        }
        
        long ans = 0;
        Pair seg = new Pair(-1L, -1L);
        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            if (current.x >= seg.y) {
                ans++;
                seg = current;
            }
        }
        
        pw.println(ans);
        pw.flush();
        pw.close();
    }
}
