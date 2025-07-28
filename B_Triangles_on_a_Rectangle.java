import java.util.Scanner;

public class B_Triangles_on_a_Rectangle {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            long w = sc.nextLong();
            long h = sc.nextLong();
            int p1 = sc.nextInt();
            long arr1[] = enterarr(p1);
            int p2 = sc.nextInt();
            long arr2[] = enterarr(p2);
            int p3 = sc.nextInt();
            long arr3[] = enterarr(p3);
            int p4 = sc.nextInt();
            long arr4[] = enterarr(p4);
            long max = 0;
            long diff1 = 0;
            long diff2 = 0;
                diff1 = Math.max(diff1, (arr1[p1-1] - arr1[0]));
                diff1 = Math.max(diff1, (arr2[p2-1] - arr2[0]));
            
                diff2 = Math.max(diff2, (arr3[p3-1] - arr3[0]));
          
                diff2 = Math.max(diff2, (arr4[p4-1] - arr4[0]));
            
            max = Math.max((diff1 * h), (diff2 * w));
            System.out.println(max);
        }
    }

    public static long[] enterarr(int size) {
        long[] arr = new long[size];
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextLong();
        }
        return arr;
    }
}
