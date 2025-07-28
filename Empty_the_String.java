import java.util.*;
import java.io.*;

public class Empty_the_String {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    
    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String s = br.readLine();
            // char ch[] = s.toCharArray();
            // int ans = 0;
            // boolean[] visited = new boolean[n];  
            int k = 0;
    
            int i = 0;
            int ans = 1;
            while (i < n) {
                char ch = s.charAt(i);
                int cnt = 0;
                while (i < n && s.charAt(i) == ch) {
                    cnt++;
                    i++;
                }
                ans = Math.max(cnt, ans);
            }
            System.out.println(ans);
        }
    
    
        }
        // pw.flush();
    }
// }