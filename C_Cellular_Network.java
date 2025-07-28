import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class C_Cellular_Network {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        long[] a = enterarr(n, br);
        long[] b = enterarr(m, br);
        
        long l = 0;
        long h = (long) 1e10;
        long ans = Long.MAX_VALUE;
        
        while (l <= h) {
            long mid = (l + h) / 2;
            
            if (predicate(a, b, mid)) {
                h = mid - 1;
                ans = Math.min(ans, mid);
            } else {
                l = mid + 1;
            }
        }
        System.out.println(ans);
    }
    
    public static boolean predicate(long[] a, long[] b, long x) {
        int n = a.length;
        int m = b.length;
        int i = 0;
        int j = 0;
        
        while (i < n && j < m) {
            long q = b[j] + x;
            long r = b[j] - x;
            
            if (a[i] <= q && a[i] >= r) {
                i++;
            } else {
                j++;
            }
        }
        
        return i == n;
    }
    
    public static long[] enterarr(int size, BufferedReader br) throws IOException {
        long[] arr = new long[size];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < size; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        
        return arr;
    }
}
