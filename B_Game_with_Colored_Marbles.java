import java.util.*;

public class B_Game_with_Colored_Marbles {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        List<Integer> results = new ArrayList<>();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            String s = scanner.next();

            int[] suffixSums = new int[n];
            int sumCount = 0;

            for (int p = n - 1; p >= 0; --p) {
                if (s.charAt(p) == '1') sumCount++;
                suffixSums[p] = sumCount;
            }

            Arrays.sort(suffixSums);
            reverse(suffixSums);

            int prefixSum = 0, answer = -1;

            for (int i = 0; i < n; ++i) {
                prefixSum += suffixSums[i];
                if (prefixSum >= k) {
                    answer = i + 1;
                    break;
                }
            }

            results.add(answer);
        }

        for (int result : results) {
            System.out.println(result);
        }
    }

    private static void reverse(int[] array) {
        int left = 0, right = array.length - 1;
        while (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}
