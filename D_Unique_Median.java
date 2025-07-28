import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class D_Unique_Median {

    public static long countGoodSubarrays(int[] a) {
        int n = a.length;
        long goodCount = 0;

        // Use a frequency map to count occurrences of each number
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0;

        for (int right = 0; right < n; right++) {
            // Add the current element to the frequency map
            freq.put(a[right], freq.getOrDefault(a[right], 0) + 1);

            // Check the conditions for good subarrays
            while (true) {
                int m1 = -1, m2 = -1;
                int count1 = 0, count2 = 0;

                // Find the two most frequent elements
                for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
                    if (entry.getValue() > count1) {
                        count2 = count1;
                        m2 = m1;
                        count1 = entry.getValue();
                        m1 = entry.getKey();
                    } else if (entry.getValue() > count2) {
                        count2 = entry.getValue();
                        m2 = entry.getKey();
                    }
                }

                // If the two most frequent elements are the same, count the good subarrays
                if (m1 == m2) {
                    goodCount += (n - right); // All subarrays from left to right are good
                    break;
                } else {
                    // Move the left pointer to shrink the window
                    freq.put(a[left], freq.get(a[left]) - 1);
                    if (freq.get(a[left]) == 0) {
                        freq.remove(a[left]);
                    }
                    left++;
                }
            }
        }

        return goodCount;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            System.out.println(countGoodSubarrays(a));
        }

        scanner.close();
    }
}