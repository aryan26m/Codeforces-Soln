import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.err;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

/**
 * template
 */
public class E_Average_and_Median {
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
    public static Comparator <Integer> getComparator()
    {
        return  new Comparator <Integer> () {
        @Override
            public int compare (Integer num1 , Integer num2) {
            if(num1<num2){return 1;} 
            else if(num1>num2){return -1;} 
       return 0;
            }
            };
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
        int ans=n;
        int low=0;
        int high=n-1;
        while (low<=high) {
            int mid = low+((high-low)/2);
            if (check1(arr,mid,x)==1) {
                ans=mid;
                high=mid-1;
            }
            else{
low=mid+1;
            }
        }
        return ans;
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
        int ans=n;
        int low=0;
        int high=n-1;
        while (low<=high) {
            int mid = low+((high-low)/2);
            if (check2(arr,mid,x)==1) {
                ans=mid;
                high=mid-1;
            }
            else{
low=mid+1;
            }
        }
        return ans;
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
        // int t=sc.nextInt();
        // while(t-- >0) {
        int n=sc.nextInt();
       long arr[]=new long[n];
       for(int i=0;i<n;i++){
        arr[i]=sc.nextLong();
       }
        long ans=median(arr,n);
        double ansavg=besavg(arr,n);
        System.out.println(ansavg);
        System.out.println(ans);
       
}
public static double maxsum(double arr[],int n){
           double d[]=new double[n];
           d[0]=arr[0];
           d[1]=arr[1]+max(d[0],0.0);
           for(int i=2;i<n;i++){
              d[i]=arr[i]+max(d[i-1], d[i-2]); 
           }
           return max(d[n-1], d[n-2]);
}
public static double besavg(long arr[],int n){
    double l=0;
    double h=1e12;
      double error=1e4;
      double avg=0;
      for(int i=0;i<100;i++){
            double mid= (l+h)/2;
            double ans[]=new double[n];
            for(int j=0;j<n;j++){
                ans[j]=arr[j]-mid;
            }
            if (maxsum(ans,n)>=0) {
                avg=mid;
                l=mid+error;
            }
            else{
                h=mid-error;
            }
      }
      return avg;
}
public static long median(long arr[],int n)
{
    long l=0;
    long h=(long)1e12;
    long med=0;
    while ( l<=h) {
        long mid=(l+h)/2;
        double temp[]=new double[n];
        for(int i=0;i<n;i++){
            if (arr[i]>=mid) {
                  temp[i]=1.0;
            }
            else{
                temp[i]=-1.0;
            }
        }
       if(maxsum(temp,n)>0){
          med=mid;
          l=mid+1;
       }
       else{
        h=mid-1;
       }
    }
    return med;
 }
}
