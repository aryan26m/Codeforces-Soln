import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class C_Traffic_Light {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            char c = st.nextToken().charAt(0);
            String s = br.readLine();
            int[] nearestG = new int[n];
            int lastG = -1;
            for (int i = 2 * n - 1; i >= 0; i--) {
                if (s.charAt(i % n) == 'g') {
                    lastG = i;
                }
                if (i < n) {
                    nearestG[i] = lastG - i;
                }
            }

            int max = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == c) {
                    max = Math.max(max, nearestG[i]);
                }
            }
            System.out.println(max);
        }
    }
}
