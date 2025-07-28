import java.util.*;
public class B_Collecting_Game {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = enterarr(n);
            long[] sortedArr = new long[n];
            
            for (int i = 0; i < n; i++) {
                sortedArr[i] = arr[i];
            }
            Arrays.sort(sortedArr);
            
            long[] preSum = new long[n];
            preSum[0] = sortedArr[0];
            for (int i = 1; i < n; i++) {
                preSum[i] = preSum[i - 1] + sortedArr[i];
            }
            
            long[] ans = new long[n];
            ans[0] = 0L;

            for (int i = 1; i < n - 1; i++) {
                long cnt = 0;
                int j = i + 1;
                while (j < n && preSum[i] >= sortedArr[j]) {
                    preSum[i] += sortedArr[j];
                    j++;
                    cnt++;
                }
                ans[i] = i + cnt;
            }

            ans[n - 1] = n - 1;

            Map<Long, Long> indexMap = new HashMap<>();
            for (int i = 0; i < n; i++) {
                indexMap.put(sortedArr[i], ans[i]);
            }
            for (int x : arr) {
                System.out.print(indexMap.get((long) x) + " ");
            }
            System.out.println();
        }
    }
    public static int[] enterarr(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        return arr;
    }
}
