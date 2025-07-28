import java.util.Scanner;

public class OddEvenDivisorCheck {

    // Function to check if B is divisible by A
    public static String isPossible(int A, int B) {
        return (B % A == 0) ? "Yes" : "No";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read values of A and B
        System.out.print("Enter A (odd divisors): ");
        int A = sc.nextInt();

        System.out.print("Enter B (even divisors): ");
        int B = sc.nextInt();

        // Output the result
        System.out.println(isPossible(A, B));
        
        sc.close();
    }
}