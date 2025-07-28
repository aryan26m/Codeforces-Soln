import java.util.*;
public class A_Alternating_Sum_of_Numbers {
   static Scanner sc=new Scanner(System.in);
    public static int[] enterarr(int N) {
        int[] arr = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = sc.nextInt();
        return arr;
    }

    public static void printarr(int[] arr) {
        // For debugging only
        for (int x : arr)
            System.out.print(x + " ");
        System.out.println();
    }

    public static boolean isPrime(long n) {
        if (n < 2)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        long sqrtN = (long) Math.sqrt(n) + 1;
        for (long i = 6L; i <= sqrtN; i += 6) {
            if (n % (i - 1) == 0 || n % (i + 1) == 0)
                return false;
        }
        return true;
    }

    public static long gcd(long a, long b) {
        if (a > b)
            a = (a + b) - (b = a);
        if (a == 0L)
            return b;
        return gcd(b % a, a);
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
  
public static void main(String[] args) {
    
    int t=sc.nextInt();
    
    while(t-- >0){
        int n=sc.nextInt();
        int arr[] = enterarr(n);
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i=i+2){
            sum1+=arr[i];
        }
        for(int i=1;i<n;i=i+2){
            sum2+=arr[i];
        }
        System.out.println(sum1-sum2);
    }
}
}
    
    