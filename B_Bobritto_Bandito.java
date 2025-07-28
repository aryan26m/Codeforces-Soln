import java.util.Scanner;

public class B_Bobritto_Bandito {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read number of test cases
        int t = sc.nextInt();
        
        // Process each test case
        for (int i = 0; i < t; i++) {
            // Read n, m, l, r
            int n = sc.nextInt();
            int m = sc.nextInt();
            int l = sc.nextInt();
            int r = sc.nextInt();
            
            // Compute r' = min(m, r)
            int rPrime = Math.min(m, r);
            // Compute l' = r' - m
            int lPrime = rPrime - m;
            
            // Output the result
            System.out.println(lPrime + " " + rPrime);
        }
        
        sc.close();
    }
}