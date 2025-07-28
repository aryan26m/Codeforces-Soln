import java.util.*;

public class E_Lost_Soul {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while (t-- >0) {
            
            int n = sc.nextInt();
            List<Integer> a = new ArrayList<>(n);
            List<Integer> b = new ArrayList<>(n);

            for (int i = 0; i < n; i++) {
                a.add(sc.nextInt());
            }
            for (int i = 0; i < n; i++) {
                b.add(sc.nextInt());
            }
            
        int i = n - 1;
        Set<Integer> hs1 = new HashSet<>();
        Set<Integer> hs2 = new HashSet<>();
        
        for (; i >= -1; i--) {
            if (i == -1 || a.get(i).equals(b.get(i))) break;
            
            if (i % 2 == 0) {
                if (hs1.contains(a.get(i)) || hs2.contains(b.get(i))) break;
                if (i + 1 < n) hs2.add(a.get(i + 1));
                if (i + 1 < n) hs1.add(b.get(i + 1));
                if (hs2.contains(a.get(i)) || hs1.contains(b.get(i))) break;
            } else {
                if (hs2.contains(a.get(i)) || hs1.contains(b.get(i))) break;
                if (i + 1 < n) hs1.add(a.get(i + 1));
                if (i + 1 < n) hs2.add(b.get(i + 1));
                if (hs1.contains(a.get(i)) || hs2.contains(b.get(i))) break;
            }
        }
        
        System.out.println(i + 1);
    }
}
}