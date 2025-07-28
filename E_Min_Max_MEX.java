import java.util.*;

public class E_Min_Max_MEX {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // Number of test cases
        
        while (t-- > 0) {
            int n = sc.nextInt(); // Length of array
            int k = sc.nextInt(); // Number of subarrays
            int[] a = new int[n]; // Array input
            
            // Input array
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            HashMap <Integer,Integer> hm=new HashMap<>();
            for (int i = 0; i < n; i++) {
                hm.put(a[i],hm.getOrDefault(a[i],0)+1);
            }
            
        }
    }
}