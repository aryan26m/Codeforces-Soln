import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C_MEX_Cycle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int x = sc.nextInt() - 1; 
            int y = sc.nextInt() - 1;             
            int[] a = new int[n];
            Arrays.fill(a, -1); 

            for (int i = 0; i < n; i++) {
                Set<Integer> ar = new HashSet<>();
                ar.add(a[(i - 1 + n) % n]); 
                ar.add(a[(i + 1) % n]); 
                if(i == x) {
                    ar.add(a[y]);
                }
                if (i == y) {
                    ar.add(a[x]); 
                }
                
                int mex = 0;
                while (ar.contains(mex)) {
                    mex++;
                }
                a[i] = mex;
            }
             
            for (int xx : a) {
                System.out.print(xx+ " ");
            }
            System.out.println();
        }
        
        sc.close();
    }
}
