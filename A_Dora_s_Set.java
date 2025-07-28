import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

/**
 * template
 */
public class A_Dora_s_Set {
    static Scanner sc = new Scanner(System.in); // Declare Scanner as static
    public static int[] enterarr(int N) {
        int[] arr = new int[N];
        for(int i = 0; i < N; i++)
            arr[i] = sc.nextInt();
        return arr;
    }
    public static void printarr(int[] arr) {
        // For debugging only
        for(int x: arr)
            System.out.print(x +" ");
        System.out.println();
    }
    public static boolean isPrime(long n)
    {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n)+1;
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
        }
        return true;
    }
    public static long gcd(long a, long b)
    {
        if(a > b)
            a = (a+b)-(b=a);
        if(a == 0L)
            return b;
        return gcd(b%a, a);
    }
    public static int[] sort(int[] arr)
    {
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
            return arr;
    }
    public static void push(TreeMap<Integer, Integer> map, int k, int v)
    {
        //map[k] += v;
        if(!map.containsKey(k))
            map.put(k, v);
        else
            map.put(k, map.get(k)+v);
    }

    public static void main(String[] args) {
      int n=sc.nextInt();
       while (n-- >0) {
         // the concept of this code this code gcd is 1 only if(a,a+1,a+2) pair choose and a must be odd in 
         //even conditioon ex a=2, (2,3),(3,4),(2,4) 2,4 gcd is 2 so not even only odd
         //if we take odd then aisoddd a+1iseven and a+2 is odd
        int l=sc.nextInt();
        int r=sc.nextInt();
        int oddcnt=0;
        for(int i=l;i<=r;i++){
            if(i%2==1){
                oddcnt++;
            }
        }
        System.out.println(oddcnt/2);
       }
    }
}
