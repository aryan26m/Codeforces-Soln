import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input
        int n = scanner.nextInt(); // Number of bars
        int k = scanner.nextInt(); // Max bars to close
        int[] bars = new int[n];   // Bar positions
        for (int i = 0; i < n; i++) {
            bars[i] = scanner.nextInt();
        }
        
        // Compute result
        int result = countValidHouses(n, k, bars);
        System.out.println(result);
        
        scanner.close();
    }
    
    public static int countValidHouses(int n, int k, int[] bars) {
        // Use a set to store all valid house numbers
        Set<Integer> validHouses = new TreeSet<>();
        
        // Sort bar positions for easier median calculation
        Arrays.sort(bars);
        
        // Try all possible numbers of bars to keep open (n-k to n)
        for (int openCount = Math.max(1, n - k); openCount <= n; openCount++) {
            // For each number of open bars, consider all subsets
            // We can simulate by checking medians of sorted positions
            if (openCount % 2 == 1) {
                // Odd number of open bars: single median
                int medianIdx = openCount / 2;
                // Consider all possible subsets of 'openCount' bars
                for (int i = 0; i <= n - openCount; i++) {
                    int median = bars[i + medianIdx];
                    if (median >= 1 && median <= 109) {
                        validHouses.add(median);
                    }
                }
            } else {
                // Even number of open bars: range of medians
                int leftMedianIdx = (openCount / 2) - 1;
                int rightMedianIdx = openCount / 2;
                for (int i = 0; i <= n - openCount; i++) {
                    int left = bars[i + leftMedianIdx];
                    int right = bars[i + rightMedianIdx];
                    // Add all houses between left and right (inclusive)
                    for (int house = left; house <= right; house++) {
                        if (house >= 1 && house <= 109) {
                            validHouses.add(house);
                        }
                    }
                }
            }
        }
        
        // Return the number of distinct valid houses
        return validHouses.size();
    }
}