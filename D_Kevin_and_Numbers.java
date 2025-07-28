import java.util.*;

public class D_Kevin_and_Numbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            int[] a = new int[n];
            int[] b = new int[m];

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextInt();
            }

            if (canTransform(a, b)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    private static boolean canTransform(int[] a, int[] b) {
        // Create frequency maps for both arrays
        HashMap<Integer, Integer> freqA = new HashMap<>();
        HashMap<Integer, Integer> freqB = new HashMap<>();

        for (int num : a) {
            freqA.put(num, freqA.getOrDefault(num, 0) + 1);
        }

        for (int num : b) {
            freqB.put(num, freqB.getOrDefault(num, 0) + 1);
        }

        // Use a max-heap to process elements in b
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int num : freqB.keySet()) {
            maxHeap.offer(num);
        }

        while (!maxHeap.isEmpty()) {
            int largest = maxHeap.poll();
            if (freqA.containsKey(largest) && freqA.get(largest) > 0) {
                freqA.put(largest, freqA.get(largest) - 1);
                if (freqA.get(largest) == 0) {
                    freqA.remove(largest);
                }
                freqB.put(largest, freqB.get(largest) - 1);
                if (freqB.get(largest) == 0) {
                    freqB.remove(largest);
                }
            } else {
                if (largest == 1) {
                    return false;
                }
                int num1 = largest / 2;
                int num2 = largest - num1;

                // Ensure valid splits
                if (num1 <= 0 || num2 <= 0) {
                    return false;
                }

                // Update freqB with the split numbers
                freqB.put(num1, freqB.getOrDefault(num1, 0) + 1);
                freqB.put(num2, freqB.getOrDefault(num2, 0) + 1);
            }
        }

        // Check if all elements in b are satisfied
        for (int count : freqB.values()) {
            if (count > 0) {
                return false;
            }
        }

        return true;
    }
}
