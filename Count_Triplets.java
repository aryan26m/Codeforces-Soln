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
public class Count_Triplets {
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

        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int testCases = Integer.parseInt(br.readLine());
    
            while (testCases-- > 0) {
                int n = Integer.parseInt(br.readLine());
                String[] input = br.readLine().split(" ");
                int[] arr = new int[n + 1];
                
                for (int i = 1; i <= n; i++) {
                    arr[i] = Integer.parseInt(input[i - 1]);
                }
                
                long output = 0;
    
                for (int i = 1; i <= n; i++) {
                    for (int j = 0; j <= 99 && i + j <= n; j++) {
                        int k = i + j;
                        int refern = Math.abs(arr[i] - arr[k]);
                        output += calculateOutput(i, k, j, refern, n);
                    }
    
                    for (int j = 1; j <= 99 && i - j >= 1; j++) {
                        int k = i - j;
                        int refern = Math.abs(arr[i] - arr[k]);
                        output += calculateOutput(i, k, j, refern, n);
                    }
                }
                
                System.out.println(output);
            }
        }
    
        private static long calculateOutput(int i, int k, int j, int refern, int n) {
            if (refern < j) {
                return 0;
            }
    
            if (refern == j) {
                return j + 1;
            } 
    
            long output = 0;
            if (refern > j && (refern - j) % 2 == 0) {
                long center1 = (i + k - refern) / 2;
                if ((i + k - refern) % 2 == 0 && center1 >= 1 && center1 <= n) {
                    output += 1;
                }
    
                long mid2 = (i + k + refern) / 2;
                if ((i + k + refern) % 2 == 0 && mid2 >= 1 && mid2 <= n) {
                    output += 1;
                }
            }
    
            return output;
        }
    }