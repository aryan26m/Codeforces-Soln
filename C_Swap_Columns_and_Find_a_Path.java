import java.util.*;

public class C_Swap_Columns_and_Find_a_Path {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr1 = new int[n];
            int[] arr2 = new int[n];
            for (int i = 0; i < n; i++) {
                arr1[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                arr2[i] = sc.nextInt();
            }

            long cr = Long.MIN_VALUE;
            long mtotoal = 0;
            for (int i = 0; i < n; i++) {
                mtotoal += Math.max(arr1[i], arr2[i]);
            }

            for (int i = 0; i < n; i++) {
               int q =  Math.min(arr1[i], arr2[i]);
                cr = Math.max(cr, mtotoal + q);
            }

            System.out.println(cr);
        }
        sc.close();
    }
}
