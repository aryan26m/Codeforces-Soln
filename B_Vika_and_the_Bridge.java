import java.util.*;

public class B_Vika_and_the_Bridge {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            ArrayList<ArrayList<Integer>> ar = new ArrayList<>();
            for (int i = 0; i <= k; i++) {
                ar.add(new ArrayList<>());
                ar.get(i).add(-1);
            }

            for (int i = 0; i < n; i++) {
                ar.get(a[i]).add(i);
            }

            for (int i = 0; i < ar.size(); i++) {
                if (ar.get(i).size() >= 1) {
                    ar.get(i).add(n);
                }
            }

            int arr2[] = new int[k + 1];
            for (int i = 1; i <= k; i++) {
                ArrayList<Integer> l1 = new ArrayList<>();
                for (int j = 1; j < ar.get(i).size(); j++) {
                    l1.add(ar.get(i).get(j) - ar.get(i).get(j - 1) - 1);
                }

                Collections.sort(l1, Collections.reverseOrder());
                if (l1.size() == 1) {
                    arr2[i] = l1.get(0) / 2;
                } else {
                    arr2[i] = Math.max(l1.get(0) / 2, l1.get(1));
                }
            }

            int ans = Integer.MAX_VALUE;
            for (int i = 1; i <= k; i++) {
                ans = Math.min(ans, arr2[i]);
            }

            System.out.println(ans);
        }
    }
}
