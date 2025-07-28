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
public class GCD_Add_Size {
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
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static int argcd(int[] arr) {
        int res = arr[0];
        for (int i = 1; i < arr.length; i++) {
            res = gcd(res, arr[i]);
            if (res == 1) {
                return 1;    }
        }
        return res;
    }

    public static int checker(int[] A) {
        int n = A.length;
        int mx = 0;

        for (int i = 0; i < (1 << n); i++) {
            List<Integer> B = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    B.add(A[j]);
                }
            }

            if (B.size() > 0) {
                int[] BArray = B.stream().mapToInt(Integer::intValue).toArray();
                int gcdB = argcd(BArray);
                int fB = B.size() + gcdB;
                mx = Math.max(mx, fB);
            }
        }
       return mx;
    }
    public static void main(String[] args) {
        int t=sc.nextInt();
        while(t-- >0) {
        int n=sc.nextInt();
        int a[]=enterarr(n);
        int res = checker(a);
        System.out.println(res);
    }

}
}
