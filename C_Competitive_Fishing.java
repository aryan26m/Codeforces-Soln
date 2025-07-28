import java.util.*;

public class C_Competitive_Fishing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();

            int[] suffixSums = new int[n];
            int sumCount = 0;

            for (int p = n - 1; p >= 0; --p) {
                if (s.charAt(p) == '1') sumCount++;
                suffixSums[p] = sumCount;
            }

            Arrays.sort(suffixSums);
            reverseArray(suffixSums);

            int prefixSum = 0, answer = -1;

            for (int i = 0; i < n; ++i) {
                prefixSum += suffixSums[i];
                if (prefixSum >= k) {
                    answer = i + 1;
                    break;
                }
            }

            System.out.println(answer);
        }

        sc.close();
    }

    private static void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}
