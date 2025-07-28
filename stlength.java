import java.io.*;
import java.util.*;

public class stlength {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int n = Integer.parseInt(br.readLine());
        long[] a = new long[n];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(input[i]);
        }
        
        Arrays.sort(a);
        long mid = (n % 2 == 1) ? a[n / 2] : a[(n / 2) - 1]; // Middle value
        
        long ans = 0;
        for (long value : a) {
            ans += Math.abs(value - mid);
        }
        
        out.println(ans);
        out.flush();
    }
}