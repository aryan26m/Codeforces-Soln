import java.util.*;
import java.io.*;

public class E_Building_an_Aquarium {

    static long n, x;
    static List<Long> v = new ArrayList<>();

    public static boolean valid(long mid) {
        long sum = 0;
        for (long i : v) {
            if (i < mid)
                sum += mid - i;
        }
        return sum <= x;
    }

    public static void solve(BufferedReader reader) throws IOException {
        String[] input = reader.readLine().split(" ");
        n = Long.parseLong(input[0]);
        x = Long.parseLong(input[1]);
        v.clear();
        
        input = reader.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            v.add(Long.parseLong(input[i]));
        }

        long left = 0, right = (long) 1e10, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (valid(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        System.out.println(left - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

        long t = 1;
        t = Long.parseLong(reader.readLine());
        while (t-- > 0) {
            solve(reader);
        }
        writer.flush();
    }
}
