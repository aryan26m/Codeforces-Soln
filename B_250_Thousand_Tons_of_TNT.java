import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class B_250_Thousand_Tons_of_TNT {
    public static List<Long> findDivisors(long n) {
        List<Long> divisors = new ArrayList<>();
        for (long i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                divisors.add(i);
                if (i != n / i) {
                    divisors.add(n / i);
                }
            }
        }
        return divisors;
    }

    public static long maxDifferenceSum(List<Long> a, long n) {
        List<Long> b = findDivisors(n);
        Collections.sort(b);
        
        // Remove duplicates
        Set<Long> set = new HashSet<>(b);
        b.clear();
        b.addAll(set);
        Collections.sort(b);  // Sort again after removing duplicates

        long mxDif = Long.MIN_VALUE;
        b.remove(b.size() - 1);  // Equivalent to b.pop_back()

        for (int i = 0; i < b.size(); i++) {
            long s = 0;
            long mx = Long.MIN_VALUE;
            long mn = Long.MAX_VALUE;

            for (int j = 0; j < a.size(); j++) {
                s += a.get(j);
                if ((j + 1) % b.get(i) == 0) {
                    mx = Math.max(s, mx);
                    mn = Math.min(s, mn);
                    s = 0;
                }
            }
            
            long dif = mx - mn;
            mxDif = Math.max(mxDif, dif);
        }
        if (n==1 || mxDif<0) {
            return 0;
        }
        return mxDif;
    }

    public static void main(String[] args) {
        // Example usage
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-- >0) {
            long n=sc.nextLong();
            ArrayList <Long> ar=new ArrayList<>();
            for(int i=0;i<n;i++){
                ar.add(sc.nextLong());
            }
            System.out.println(maxDifferenceSum(ar, n));
        }
    }
}
