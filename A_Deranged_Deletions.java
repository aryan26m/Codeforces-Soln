import java.util.*;

public class A_Deranged_Deletions {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            long[] h = new long[n];
            for (int i = 0; i < n; i++) {
                h[i] = sc.nextLong();
            }

            long currentHeight = h[k - 1];
            long time = 0;

            // Collect all towers that are at least as tall as starting tower
            List<Long> candidates = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (h[i] >= currentHeight) {
                    candidates.add(h[i]);
                }
            }

            Collections.sort(candidates); // Always move to taller or equal towers

            boolean safe = true;
            for (int i = 1; i < candidates.size(); i++) {
                long nextHeight = candidates.get(i);
                long teleportTime = Math.abs(currentHeight - nextHeight);

                // During teleport, you're still on the current tower
                // Water rises each second → water level at time+teleportTime
                if (time + teleportTime >= currentHeight) {
                    safe = false;
                    break;
                }

                // Update time and tower
                time += teleportTime;
                currentHeight = nextHeight;
            }

            System.out.println(safe ? "YES" : "NO");
        }

        sc.close();
    }
}
