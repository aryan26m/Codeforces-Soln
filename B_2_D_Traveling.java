import java.io.*;
import java.util.*;

public class B_2_D_Traveling {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static int[] enterarr(int N) throws IOException {
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    public static void printarr(int[] arr) throws IOException {
        for (int x : arr) {
            bw.write(x + " ");
        }
        bw.write("\n");
    }

    public static boolean isPrime(long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        long sqrtN = (long) Math.sqrt(n) + 1;
        for (long i = 6L; i <= sqrtN; i += 6) {
            if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
        }
        return true;
    }

    public static long gcd(long a, long b) {
        if (a > b) a = (a + b) - (b = a);
        if (a == 0L) return b;
        return gcd(b % a, a);
    }

    public static int[] sort(int[] arr) {
        ArrayList<Integer> ls = new ArrayList<>();
        for (int x : arr) ls.add(x);
        Collections.sort(ls);
        for (int i = 0; i < arr.length; i++) arr[i] = ls.get(i);
        return arr;
    }

    public static void push(TreeMap<Integer, Integer> map, int k, int v) {
        if (!map.containsKey(k)) map.put(k, v);
        else map.put(k, map.get(k) + v);
    }

    public static Comparator<Integer> getComparator() {
        return (num1, num2) -> {
            if (num1 < num2) return 1;
            else if (num1 > num2) return -1;
            return 0;
        };
    }

    public static boolean search(int arr[], int target) {
        int n = arr.length;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (arr[mid] == target) return true;
            else if (arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }

    public static int lowerBound(int arr[], int x) {
        int n = arr.length, ans = n, low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (check1(arr, mid, x) == 1) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }

    public static int check1(int arr[], int mid, int x) {
        return arr[mid] >= x ? 1 : 0;
    }

    public static int upperBound(int arr[], int x) {
        int n = arr.length, ans = n, low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (check2(arr, mid, x) == 1) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }

    public static int check2(int arr[], int mid, int x) {
        return arr[mid] > x ? 1 : 0;
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bw.write(soln(n, k, a, b) + "\n");
        }
        bw.flush();
    }

    public static long soln(int n, int k, int a, int b) throws IOException {
        int x[] = new int[n + 1];
        x[0] = -1;
        int y[] = new int[n + 1];
        y[0] = -1;
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
        }
        if (a <= k && b <= k) return 0;
        long ans1 = (long) Math.abs(x[b] - x[a]) + (long) Math.abs(y[b] - y[a]);
        long min1 = Long.MAX_VALUE, min2 = Long.MAX_VALUE;
        for (int i = 1; i <= k; i++) {
            long diff1 = (long) Math.abs(x[i] - x[a]) + (long) Math.abs(y[i] - y[a]);
            min1 = Math.min(min1, diff1);
        }
        for (int i = 1; i <= k; i++) {
            long diff1 = (long) Math.abs(x[i] - x[b]) + (long) Math.abs(y[i] - y[b]);
            min2 = Math.min(min2, diff1);
        }
        long ans2 = min1 + min2;
        if (k == 0 || ans2 < 0) return ans1;
        return Math.min(ans1, ans2);
    }
}
