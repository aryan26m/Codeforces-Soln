import java.util.Arrays;

public class MaxPossibleSum {
    // Function to calculate the MEX of the array
    private static int calculateMEX(int[] arr) {
        boolean[] present = new boolean[arr.length + 1];
        for (int value : arr) {
            if (value < present.length) {
                present[value] = true;
            }
        }
        for (int i = 0; i < present.length; i++) {
            if (!present[i]) {
                return i;
            }
        }
        return present.length;
    }

    // Function to calculate the maximum possible sum
    public static int maxPossibleSum(int[] A) {
        Arrays.sort(A);
        int n = A.length;
        int maxSum = Arrays.stream(A).sum(); // Initial sum
        int suffixSum = maxSum; // Start with full sum as suffix sum

        for (int i = 0; i < n; i++) {
            int currentMEX = i;
            suffixSum -= A[i];
            int candidateSum = currentMEX * (i + 1) + suffixSum;
            maxSum = Math.max(maxSum, candidateSum);
        }

        return maxSum;
    }

    public static void main(String[] args) {
        int[] A = {1, 0, 4, 1, 2};
        int result = maxPossibleSum(A);
        System.out.println("Maximum possible sum: " + result);
    }
}
