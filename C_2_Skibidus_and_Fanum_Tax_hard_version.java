import java.util.*;

public class C_2_Skibidus_and_Fanum_Tax_hard_version {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // Number of test cases
        while (t-- > 0) {
            int n = sc.nextInt(); // Size of array a
            int m = sc.nextInt(); // Size of array b
            int[] a = new int[n];
            int[] b = new int[m];
            
            // Input array a
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            
            // Input array b
            for (int i = 0; i < m; i++) {
                b[i] = sc.nextInt();
            }
            
            // Sort array b to facilitate searching for optimal b_j
            Arrays.sort(b);
            
            // Variable to keep track of the last value selected in the sorted a array
            long lastValue = Long.MIN_VALUE;
            boolean possible = true;

            for (int i = 0; i < n; i++) {
                // We need to pick the minimum value between a[i] and (b_j - a[i]) such that the sequence is non-decreasing
                long currentValue = a[i];
                
                // We will search for the optimal value (b_j - a[i])
                long target = b[m - 1] - a[i]; // Maximum possible b_j - a[i] 
                int pos = binarySearch(b, target); // Find the largest b_j <= target
                
                if (pos != -1 && b[pos] - a[i] <= currentValue) {
                    currentValue = b[pos] - a[i];
                }
                
                // Check if we can maintain the order
                if (currentValue < lastValue) {
                    possible = false;
                    break;
                }
                
                lastValue = currentValue; // Update last value selected
            }
            
            if (possible) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        
        sc.close();
    }

    // Binary search to find the largest b[j] such that b[j] <= target
    public static int binarySearch(int[] b, long target) {
        int low = 0, high = b.length - 1, res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (b[mid] <= target) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
}
