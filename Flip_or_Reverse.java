import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Flip_or_Reverse {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt(); // Number of test cases

        while (T-- > 0) {
            int N = scanner.nextInt(); // Length of the binary strings
            String A = scanner.next(); // Binary string A
            String B = scanner.next(); // Binary string B

            // List to store the operations
            List<String> operations = new ArrayList<>();

            // Traverse the strings and fix mismatches
            for (int i = 0; i < N; i++) {
                if (A.charAt(i) != B.charAt(i)) {
                    // If there is a mismatch, check if the next position also has a mismatch
                    if (i + 1 < N && A.charAt(i + 1) != B.charAt(i + 1)) {
                        // Pair the current and next mismatches into a single flip operation
                        operations.add("1 " + (i + 1) + " " + (i + 2));
                        i++; // Skip the next position since it's already fixed
                    } else {
                        // Single mismatch, flip only this position
                        operations.add("1 " + (i + 1) + " " + (i + 1));
                    }
                }
            }

            // Output the number of operations and the operations themselves
            System.out.println(operations.size());
            for (String op : operations) {
                System.out.println(op);
            }
        }

        scanner.close();
    }
}