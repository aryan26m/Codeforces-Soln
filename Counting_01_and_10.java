import java.util.Scanner;

public class Counting_01_and_10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt(); // Number of test cases

        while (T-- > 0) {
            int N = scanner.nextInt(); // Length of the binary string
            long distinctPairs = 0;

            // Iterate over all possible values of k (number of 1s)
            for (int k = 0; k <= N; k++) {
                // Calculate the maximum number of 01 subsequences
                long maxX = (long) k * (N - k);
                // Add the number of distinct (X, Y) pairs for this k
                distinctPairs += maxX + 1;
            }

            // Due to symmetry, we can optimize by calculating up to N/2 and doubling
            // However, for simplicity, the above loop works for all cases
            System.out.println(distinctPairs);
        }

        scanner.close();
    }
}