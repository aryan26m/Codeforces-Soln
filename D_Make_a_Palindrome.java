import java.util.*;

public class D_Make_a_Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();  // Number of test cases

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            if (isPossibleToMakePalindrome(a, n, k)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        sc.close();
    }

    private static boolean isPossibleToMakePalindrome(int[] a, int n, int k) {
        if (k == 1) return true;
        int left = 0;
        int right = n - 1;
        int matchCount = 0;

        while (left < right && a[left] == a[right]) {
            left++;
            right--;
            matchCount++;
        }

        return matchCount >= k;
    }
}
