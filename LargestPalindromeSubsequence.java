import java.util.Scanner;

public class LargestPalindromeSubsequence {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(findLongestPalindromeSubseq(str));
    }

    public static String findLongestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];

        // Fill the DP array
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct the longest palindromic subsequence
        StringBuilder sb = new StringBuilder();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (s.charAt(i) == s.charAt(j)) {
                sb.append(s.charAt(i));
                i++;
                j--;
            } else if (dp[i + 1][j] > dp[i][j - 1]) {
                i++;
            } else {
                j--;
            }
        }

        // Creating the final palindrome
        String half = sb.toString();
        String reverseHalf = new StringBuilder(half).reverse().toString();
        if (i - 1 != j + 1) { // If the string is of odd length
            sb.append(reverseHalf.substring(1));
        } else {
            sb.append(reverseHalf);
        }

        return sb.toString();
    }
}
