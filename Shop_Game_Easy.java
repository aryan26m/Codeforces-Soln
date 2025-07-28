import java.util.*;

public class Shop_Game_Easy {
    static final int MOD = 1_000_000_007;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            Long[] arr = new Long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextLong();
            }
            String s = sc.next();

            Arrays.sort(arr, Collections.reverseOrder());

            // Pick top-k elements
            List<Long> items = new ArrayList<>();
            for (int i = 0; i < k; i++) {
                items.add(arr[i]);
            }

            // Sort them descending to simulate max/min easily
            Collections.sort(items, Collections.reverseOrder());

            int l = 0;
            int r = k - 1;
            long ans = 0;

            for (int i = 0; i < k; i++) {
                if (s.charAt(i) == '1') {
                    ans = (ans + items.get(l++)) % MOD;
                } else {
                    ans = (ans + items.get(r--)) % MOD;
                }
            }

            System.out.println(ans);
        }
    }
}
