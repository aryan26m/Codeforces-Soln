import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.loadLibrary;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

/**
 * template
 */
public class C_Reducing_Fractions {
    static Scanner sc = new Scanner(System.in); // Declare Scanner as static
    public static int[] enterarr(int N) {
        int[] arr = new int[N];
        for(int i = 0; i < N; i++)
            arr[i] = sc.nextInt();
        return arr;
    }
class Multiset<T extends Comparable<T>> {
        private final TreeSet<T> treeSet;
        private final HashMap<T, Integer> countMap;
        private int size;

        public Multiset() {
            this.treeSet = new TreeSet<>();
            this.countMap = new HashMap<>();
            this.size = 0;
        }

        public void add(T element) {
            treeSet.add(element);
            countMap.put(element, countMap.getOrDefault(element, 0) + 1);
            size++;
        }

        public void remove(T element) {
            if (!countMap.containsKey(element)) return;
            int count = countMap.get(element);
            if (count == 1) {
                countMap.remove(element);
                treeSet.remove(element);
            } else {
                countMap.put(element, count - 1);
            }
            size--;
        }

        public T first() {
            return treeSet.first();
        }

        public T last() {
            return treeSet.last();
        }

        public T pollFirst() {
            T first = first();
            remove(first);
            return first;
        }

        public T pollLast() {
            T last = last();
            remove(last);
            return last;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public int size() {
            return size;
        }
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
    public static long power(long a, long b) {
        long result = 1;
        // long mod = 1_000_000_007; // Optional: use a large prime number for modular arithmetic
    
        while (b > 0) {
            if ((b & 1) == 1) { // If b is odd
                result = (result * a);
            }
            a = (a * a);
            b >>= 1; // Divide b by 2
        }
    
        return result;
    }
    
   public static  int limit=(int)1e7+1;
  public static  int spf[]=new int[limit];
  public static  boolean prime[]=new boolean[limit];
  public static void main(String[] args) {
      int n=sc.nextInt();
      int k=sc.nextInt();
      int a[]=enterarr(n);
      int b[]=enterarr(k);
      spf();
      HashMap <Integer,Integer> nm=new HashMap<>();
      for(int i=0;i<n;i++){
        int x=a[i];
        while (x>1) {
            int p=spf[x];
            int cnt=0;
            // System.out.println(p);
            while(x%p==0) {
                x=x/p;
                cnt++;
            }
            nm.put(p,nm.getOrDefault(p,0)+cnt);
        }
      }

      HashMap <Integer,Integer> dm=new HashMap<>();
      for(int i=0;i<k;i++){
        int x=b[i];
        while (x>1) {
            int p=spf[x];
            int cnt=0;
            while (x%p==0) {
                x=x/p;
                cnt++;
            }
            dm.put(p,dm.getOrDefault(p,0)+cnt);
        }
    }
    HashMap<Integer,Integer> div=new HashMap<>();
    for(HashMap.Entry<Integer,Integer> x : nm.entrySet()){
        int key=x.getKey();
        int val=x.getValue();
        div.put(key,(int)Math.min(val,dm.getOrDefault(key,0)));
    }
    nm = new HashMap<>(div);
    dm = new HashMap<>(div);
    // System.out.println(dm);
    for(int i=0;i<n;i++){
        int x=a[i];
        while (x>1) {
            int p=spf[x];
            int cnt=0;
            while (x%p==0) {
                x=x/p;
                cnt++;
            }
            cnt=Math.min(cnt,nm.getOrDefault(p,0));
            nm.put(p,nm.getOrDefault(p,0)-cnt);
            a[i]/=power(p, cnt);
        }
    }
    // System.out.println(dm);
    for(int i=0;i<k;i++){
        int x=b[i];
        while (x>1) {
            int p=spf[x];
            int cnt=0;
            while (x%p==0) {
                x=x/p;
                cnt++;
            }
            cnt=Math.min(cnt,dm.getOrDefault(p,0));
            // System.out.println(p+" cnt = "+cnt);
            dm.put(p,dm.getOrDefault(p,0)-cnt);
            b[i]/=power(p, cnt);
        }
    }
        System.out.println(a.length+" "+b.length);
        for(int i=0;i<n;i++){
            System.out.print(a[i]+" ");
        }
        System.out.println();
        for(int i=0;i<k;i++){
            System.out.print(b[i]+" ");
        }
    
    }
    public static void spf() {
        Arrays.fill(spf,Integer.MAX_VALUE);
        for(int i=2;i<limit;i++){
            if (prime[i]==false) {       
            spf[i]=i;
            s
            for(long j=(long)i*i;j<limit;j+=i){
                spf[(int)j]=min(spf[(int)j], i);
                prime[(int)j]=true;
            }
        }  
    }
    }

}