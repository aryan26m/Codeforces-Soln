import java.util.*;

public class Colorful_Tree_Easy_Version {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt(); 
            HashSet<Integer>[] adj = new HashSet[N + 1];
            for (int i = 1; i <= N; i++) {
                adj[i] = new HashSet<>();
            }
            for (int i = 0; i < N - 1; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }
            
            int leafCount = 0;
              for (int i = 1; i <= N; i++) {
                if (adj[i].size() == 1) {
                    leafCount++;
                }
            }
      int internalCount = N - leafCount;
            int beauty = leafCount * 3 + internalCount * 2;
            
            System.out.println(beauty);
        }
        
        sc.close();
    }
}