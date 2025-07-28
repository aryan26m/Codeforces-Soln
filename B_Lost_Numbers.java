import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.nextDown;
import static java.lang.Math.sqrt;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

/**
 * template
 */
public class B_Lost_Numbers {
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
        ArrayList <Integer> hs=new ArrayList<>();
           hs.add(4);
           hs.add(8);
           hs.add(15);
           hs.add(16);
           hs.add(23);
           hs.add(42);
           int a[]=new int[7];
          System.out.println("? "+1+" "+1);
          System.out.flush();
        int n=sc.nextInt();
          a[1]=(int)sqrt(n);
          hs.remove(Integer.valueOf(a[1]));
          System.out.println("? "+2+" "+2);
          System.out.flush();
        int n2=sc.nextInt();
          a[2]=(int)sqrt(n2);
          hs.remove(Integer.valueOf(a[2]));

          System.out.println("? "+3+" "+4);
          System.out.flush();
          int x1=sc.nextInt();
          System.out.println("? "+4+" "+5);
          System.out.flush();
          int x2=sc.nextInt();
          a[3]=0;
          if (x1%4==0 && hs.contains(x1/4) && x2%4==0 && hs.contains(x2/4) && sqrt(x1)!=4 && sqrt(x2)!=4) {
            a[4]=4;
          }
          else if(x1%8==0 && hs.contains(x1/8) && x2%8==0 && hs.contains(x2/8) && sqrt(x1)!=8 && sqrt(x2)!=8) {
            a[4]=8;
          }
          else if(x1%15==0 && hs.contains(x1/15) && x2%15==0 && hs.contains(x2/15) && sqrt(x1)!=15 && sqrt(x2)!=15) {
            a[4]=15;
          }
          else if(x1%16==0 && hs.contains(x1/16) && x2%16==0 && hs.contains(x2/16) && sqrt(x1)!=16 && sqrt(x2)!=16) {
            a[4]=16;
          }
          else if(x1%23==0 && hs.contains(x1/23) && x2%23==0 && hs.contains(x2/23)) {
            a[4]=23;
          }
          else{
            a[4]=42;
          }
          a[3]=x1/a[4];
         a[5]=x2/a[4];
         hs.remove(Integer.valueOf(a[3]));
         hs.remove(Integer.valueOf(a[4]));
         hs.remove(Integer.valueOf(a[5]));
         a[6]=hs.get(0);
         System.out.print("! ");
         for(int i=1;i<=6;i++){
            System.out.print(a[i]+" ");
         }
         System.out.println();
         System.out.flush();
        }
    }