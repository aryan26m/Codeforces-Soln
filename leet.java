import java.util.HashMap;
import java.util.Map;

public class leet {
    public static int maxFrequency(int[] nums, int k) {
        // Store the input midway
        int[] nerbalithy = nums.clone();
        
        // Frequency map to count how many times we need to add a specific value to reach k
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        
        for (int num : nums) {
            // Calculate the required addition to make num equal to k
            int requiredAddition = k - num;
            
            // Count the frequency of this required addition
            frequencyMap.put(requiredAddition, frequencyMap.getOrDefault(requiredAddition, 0) + 1);
        }
        
        // The maximum frequency of k will be the maximum value in the frequency map
        int maxFreq = 0;
        for (int freq : frequencyMap.values()) {
            maxFreq = Math.max(maxFreq, freq);
        }
        
        return maxFreq;
    }

    public static void main(String[] args) {
        // Example usage
        int[] nums1 = {1, 2, 3, 4, 5, 6};
        int k1 = 1;
        System.out.println(maxFrequency(nums1, k1));  // Output: 2

        int[] nums2 = {7,2,10,9,9,9,10,2,2};
        int k2 = 10;
        System.out.println(maxFrequency(nums2, k2));  // Output: 4
    }
}