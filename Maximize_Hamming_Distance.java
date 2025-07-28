
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

public class Maximize_Hamming_Distance {
    static class Pair{
        int first;
        int second;
        int third;
    
        Pair() {
            first = 0;
            second = 0;
            third = 0;
        }
    }
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
            System.out.print(x);
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
public static boolean search(int arr[],int target){
 int n=arr.length;
int low=0;
 int high=n-1;
 while(low<=high){
    int mid = low+((high-low)/2);
    if(arr[mid
                ]==target){
        return true;
                }
    else if(arr[mid
                ]>target){
        high=mid-1;
                }
    else{
        low=mid+1;
                }
            }
return false;
        }

public static int lowerBound(int arr[],int x){
        int n=arr.length;
        int cnt=n;
        int low=0;
        int high=n-1;
        while (low<=high) {
            int mid = low+((high-low)/2);
            if (check1(arr,mid,x)==1) {
                cnt=mid;
                high=mid-1;
            }
            else{
low=mid+1;
            }
        }
        return cnt;
    }
    public static int check1(int arr[],int mid ,int x){
        if (arr[mid]>=x) {
            return 1;
        }
        else{
            return 0;
        }
    }
    public static int upperbBound(int arr[],int x){
        int n=arr.length;
        int cnt=n;
        int low=0;
        int high=n-1;
        while (low<=high) {
            int mid = low+((high-low)/2);
            if (check2(arr,mid,x)==1) {
                cnt=mid;
                high=mid-1;
            }
            else{
low=mid+1;
            }
        }
        return cnt;
    }
    public static int check2(int arr[],int mid ,int x){
        if (arr[mid]>x) {
            return 1;
        }
        else{
            return 0;
        }
    }


   
    public static void main(String[] args) {
        int t = sc.nextInt(); 
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            List<Pair> arr = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                arr.add(new Pair());
            }

            long cnt = 0;

            for (int j = 0; j < m; j++) {
                String s = sc.next();  

                for (int i = 0; i < s.length(); i++) {
                    char ch = s.charAt(i);
                    Pair Pair = arr.get(i);
                    
                    if (ch == '0') {
                        Pair.first++;
                    } else if (ch == '1') {
                        Pair.second++;
                    } else {
                        Pair.third++;
                    }
                }
            }

            // Process each Pair object to calculate the result
            for (int i = 0; i < n; i++) {
                Pair Pair = arr.get(i);
                int first = Pair.first;
                int second = Pair.second;
                int third = Pair.third;

                // Distribute the third between first and second
                while (third-- > 0) {
                    if (first <= second) {
                        first++;
                    } else {
                        second++;
                    }
                }

                cnt += (long) first * second;
            }
            System.out.println(cnt);
        }

        sc.close();
    }
}