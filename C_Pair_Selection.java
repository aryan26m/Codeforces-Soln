
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
public class C_Pair_Selection {
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
          
            int n=sc.nextInt();
            int k=sc.nextInt();
            ArrayList <Pair> ar= new ArrayList<>();
            for(int i=0;i<n;i++){
                ar.add(new Pair(sc.nextDouble(),sc.nextDouble()));
            }
            double pre=1e7;
            double l=0;
            double h=1e6;
            double ans=0;
            for(int i=0;i<50;i++){
                double mid=(l+h)/2;
                // Array[]=new double[n];
               ArrayList <Double> arr=new ArrayList<>();
                for(int j=0;j<n;j++){
                    arr.add(ar.get(j).a-(mid*ar.get(j).b));
                }
                if (predicate(arr, k, n)) {
                    ans=mid;
                    l=mid+pre;
                }
                else{
                    h=mid-pre;
                }
            }
            System.out.printf("%.7f%n", ans);
    }
    public static boolean predicate(ArrayList <Double> arr,int k,int n){
                        Collections.sort(arr);
                        // Collections.reverse(arr);
                        double sum=0;
                        for(int i=n-1;i>n-1-k;i--){
                            sum+=arr.get(i);
                        }
                       return sum>=0;
    }
    }
     class Pair {
       double a;
     double b;
     Pair(double a, double b){
        this.a=a;
        this.b=b;
     } 
    }