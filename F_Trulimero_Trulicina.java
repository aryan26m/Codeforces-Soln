import java.util.*;

public class F_Trulimero_Trulicina {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); 
        
        while (t-- > 0) {
            int n = sc.nextInt(); 
            int m = sc.nextInt(); 
            int k = sc.nextInt(); 
            int[][] grid = new int[n][m];
            
            if (m%k==0) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        grid[i][j] = (i + j) % k + 1;
                    }
                }
            } 
            else {
                int current = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        grid[i][j] = 1+(current%k);
                       current++;
                    }
                }
            }
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    System.out.print(grid[i][j] + " ");
                }
                System.out.println();
            }
        }
        
        
        sc.close();
    }
}