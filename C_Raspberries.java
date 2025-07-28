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
public class C_Raspberries {
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
   int t=sc.nextInt();
   while (t-- >0) {
    int n=sc.nextInt();
    int k=sc.nextInt();
    int  arr[]=enterarr(n);
     if (k==2) {
         int min=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if (arr[i]%2==0) {
               min=Math.min(min, 0);
               break;
            }
        }
        min=Math.min(min, 1);
        if (min<0) {
            System.out.println(0); 
        }
        else{
            System.out.println(min); 
        }      
     }
     else if (k==3) {
        int min=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if (arr[i]%3==0) {
                min=Math.min(min, 0);
            }
            if ((arr[i]+1)%3==0) {
                min=Math.min(min, 1);
            }
            if ((arr[i]+2)%3==0) {
                min=Math.min(min, 2);
            }
        }     if (min<0) {
            System.out.println(0); 
        }
        else{
            System.out.println(min); 
        }
     }
     else if (k==4) {
        int min=Integer.MAX_VALUE;
        int count=0;
        for(int i=0;i<n;i++){
            if ((arr[i]%4)==0) {
                min=Math.min(min, 0);
                break;
            }
            if ((arr[i]+1)%4==0) {
                min=Math.min(min, 1);
            }
            if (arr[i]%2==0) {
                count++;
            }
            else if (count==2) {
                min=Math.min(min, 0);
            }
        }
        min=Math.min(min, 2-count);
        if (min<0) {
            System.out.println(0); 
        }
        else{
            System.out.println(min); 
        }
     }
     else if(k==5){
        int min=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if (arr[i]%5==0) {
               min=Math.min(min,0);
            }
            if ((arr[i]+1)%5==0) {
                min=Math.min(min, 1);
            }
            if ((arr[i]+2)%5==0) {
                min=Math.min(min, 2);
            }
            if ((arr[i]+3)%5==0) {
                min=Math.min(min, 3);
            }
            if ((arr[i]+4)%5==0) {
                min=Math.min(min, 4);
            }
        }
        if (min<0) {
            System.out.println(0); 
        }
        else{
            System.out.println(min); 
        }
     }
}
    }


}
