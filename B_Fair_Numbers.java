import java.util.Scanner;

public class B_Fair_Numbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCases = sc.nextInt();
        while (testCases-- > 0) {
            long n = sc.nextLong();
            long fairNumber = findFairNumber(n);
            System.out.println(fairNumber);
        }
    }

    public static long findFairNumber(long n) {
        long num = n;
        while (!isFair(num)) {
            num++;
        }
        return num;
    }

    public static boolean isFair(long num) {
        long originalNum = num;
        while (num > 0) {
            long digit = num % 10;
            num /= 10;
            if (digit != 0 && originalNum % digit != 0) {
                return false;
            }
        }
        return true;
    }
}
