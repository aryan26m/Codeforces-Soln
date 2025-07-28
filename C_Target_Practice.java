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
public class C_Target_Practice {
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
// int t=sc.nextInt();
// int arr[]=new int[10];
// for(int i=0;i<=4;i++){
// arr[i]=i+1;
// arr[9-i]=i+1;
// }
//         while (t-- >0) {
//             long count=0;
//             sc.nextLine();
//             for(int i=0;i<10;i++){
//                 String s=sc.nextLine();
//                 for(int j=0;j<s.length();j++){
//                     if (s.charAt(j)=='X') {
//                             count+=arr[j];
//                             // System.out.print(count+);
//                          }
//                 }

//             }
//             System.out.println(count);
//       }  
//     }
// }


        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        for (int testCase = 0; testCase < t; testCase++) {
            char[][] grid = new char[10][10];
            for (int i = 0; i < 10; i++) {
                grid[i] = sc.nextLine().toCharArray();
            }
            System.out.println(calculatePoints(grid));
        }
    }

    private static int calculatePoints(char[][] grid) {
        int points = 0;
        int[] ringPoints = {1, 2, 3, 4, 5};

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (grid[i][j] == 'X') {
                    if (i == 0 || i == 9 || j == 0 || j == 9) {
                        points += ringPoints[0];
                        System.out.print(points+" ");
                    } else if (i == 1 || i == 8 || j == 1 || j == 8) {
                        points += ringPoints[1];
                        System.out.print(points+" ");
                    } else if (i == 2 || i == 7 || j == 2 || j == 7) {
                        points += ringPoints[2];
                        System.out.print(points+" ");
                    } else if (i == 3 || i == 6 || j == 3 || j == 6) {
                        points += ringPoints[3];
                        System.out.print(points+" ");
                    } else {
                        points += ringPoints[4];
                        System.out.print(points+" ");
                    }
                }
            }
        }
        return points;
    }
}

