import java.io.*;
import java.util.*;

public class F_Smaller {
    public static void main(String[] args) throws IOException {
        // Use BufferedReader for fast input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder(); // StringBuilder for fast output

        int t = Integer.parseInt(br.readLine()); // Number of test cases
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine()); // Number of operations
            long cnt1 = 1; // Counter for 'x == 1'
            long cnt2 = 1; // Counter for 'x == 2'
            boolean onlya = true; // Tracks if all 'x == 1' strings contain only 'a'
            boolean flag = false; // Tracks if a non-'a' character is encountered

            while (n-- > 0) {
                String[] input = br.readLine().split(" ");
                int x = Integer.parseInt(input[0]);
                long k = Long.parseLong(input[1]); // Use `long` for k
                String s = input[2];

                if (flag) {
                    output.append("YES\n");
                } else if (x == 2) {
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) != 'a') {
                            flag = true; // Non-'a' character found
                            break;
                        }
                    }
                    if (flag) {
                        output.append("YES\n");
                    } else {
                        cnt2 += k * s.length(); // Update counter for `x == 2`
                        if (cnt1 < cnt2 && onlya) {
                            output.append("YES\n");
                        } else {
                            output.append("NO\n");
                        }
                    }
                } else { // Case `x == 1`
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) == 'a') {
                            cnt1 += k; // Update counter for `x == 1`
                        } else {
                            onlya = false; // String contains non-'a' characters
                        }
                    }
                    if (cnt1 < cnt2 && onlya) {
                        output.append("YES\n");
                    } else {
                        output.append("NO\n");
                    }
                }
            }
        }

        // Print all results at once
        System.out.print(output);
    }
}