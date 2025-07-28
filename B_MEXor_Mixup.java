import java.util.*;

public class B_MEXor_Mixup {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        final int N = 300000 + 5;
        long[] xorVal = new long[N];
        
        for (int i = 1; i < N; i++) {
            xorVal[i] = xorVal[i - 1] ^ i;
        }
        
        while (t-- > 0) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long mnLen = a;
            long val = xorVal[(int) a - 1];
            
            if (val != b) {
                long req = val ^ b;
                if (req == a) {
                    System.out.println(mnLen + 2);
                } else {
                    System.out.println(mnLen + 1);
                }
            } else {
                System.out.println(mnLen);
            }
        }
        sc.close();
    }
}
