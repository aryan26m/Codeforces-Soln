import java.util.Arrays;
import java.util.Scanner;

public class MinimizeSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // Number of test cases

        while (t-- > 0) {
            int n = scanner.nextInt(); // Length of sequence a
            int m = scanner.nextInt(); // Number of types of magic
            int k = scanner.nextInt(); // Maximum number of operations

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt(); // Read sequence a
            }

            int[] b = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt(); // Read magic types b
            }

            // Step 1: Compute the minimum possible value for each ai
            int[] minA = new int[n];
            for (int i = 0; i < n; i++) {
                minA[i] = a[i]; // Start with the original value
                for (int j = 0; j < m; j++) {
                    minA[i] = Math.min(minA[i], a[i] & b[j]); // Update with the minimum value
                }
            }

            // Step 2: Sort the original array and the minimum values
            Arrays.sort(a);
            Arrays.sort(minA);

            // Step 3: Replace the largest k elements in a with the smallest k elements in minA
            for (int i = 0; i < Math.min(k, n); i++) {
                a[n - 1 - i] = minA[i]; // Replace the largest elements
            }

            // Step 4: Calculate the final sum
            long sum = 0;
            for (int value : a) {
                sum += value; // Calculate the sum
            }

            // Output the result for the current test case
            System.out.println(sum);
        }

        scanner.close();
    }
}