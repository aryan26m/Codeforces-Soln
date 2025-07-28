import java.util.*;
public class B_Minimise_Sum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for(int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            long ans=a[0];
            if (n==1 || a[0]==0) {
                System.out.println(ans);
            }           
            else{
                ans+=Math.min(a[0],a[1]);
            
                System.out.println(ans);
            }
        }
    }
}