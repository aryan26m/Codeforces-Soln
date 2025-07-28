import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A_Helmets_in_Night_Light {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int p = sc.nextInt();
            int[] arr1 = new int[n];
            int[] arr2 = new int[n];
            for (int i = 0; i < n; i++) {
                arr1[i] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                // arr1[i] = sc.nextInt();
                arr2[i] = sc.nextInt();
            }

            Integer[] indices = new Integer[arr1.length];
            for (int i = 0; i < arr1.length; i++) {
                indices[i] = i;
            }
            Arrays.sort(indices, Comparator.comparingInt(i -> arr2[i]));
            int[] sortedArr1 = new int[arr1.length];
            int[] sortedArr2 = new int[arr2.length];
            for (int i = 0; i < indices.length; i++) {
                sortedArr1[i] = arr1[indices[i]];
                sortedArr2[i] = arr2[indices[i]];
            }
            // System.out.println("Sorted arr1: " + Arrays.toString(sortedArr1));
            // System.out.println("Sorted arr2: " + Arrays.toString(sortedArr2));
       
            int i = 0;
            long ans = p;
            n = n - 1;
            while (n > 0 && i < sortedArr1.length) {
                if (sortedArr2[i]>p) {
                    n--;
                    ans+=p;                    
                }
                else{
                    int shareCount = Math.min(n, sortedArr1[i]);
                    // System.out.println(shareCount+"  minn  ");
                    ans += shareCount * sortedArr2[i];
                    n -= shareCount;
                    i++;
                }
            }
            System.out.println(ans);
        }
    }
}