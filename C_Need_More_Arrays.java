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
public class C_Need_More_Arrays {
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
        private int n;

        public Multiset() {
            this.treeSet = new TreeSet<>();
            this.countMap = new HashMap<>();
            this.n = 0;
        }

        public void add(T element) {
            treeSet.add(element);
            countMap.put(element, countMap.getOrDefault(element, 0) + 1);
            n++;
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
            n--;
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
            return n == 0;
        }

        public int n() {
            return n;
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

    public static void main(String[] args) {
        int t=sc.nextInt();
        while(t-- >0) {
        int n=sc.nextInt();
        //     int n = sc.nextInt(); // Read input n
        // List<Integer> a = new ArrayList<>();
int a[]=enterarr(n);
       

        if (n == 1) {
            System.out.println(1);
            continue;
        }

        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : a) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        int result = 0;
     
        int index = 0;

        for (index = 0; index < n - 1; index++) {

            
            if (a[index + 1] - a[index] == 1) {
            
                result += 1;
            
                index += countMap.get(a[index + 1]);
            
            } else if (a[index + 1] - a[index] == 0) {
            
                continue;
            
            }
            
            else {
            
                result++;
            
            }
        }

        if (index == n - 1) {
            result++;
        }   
        System.out.println(result);
    }

}
}
