import java.util.*;

class Pair {
    int no, idx;

    Pair(int no, int idx) {
        this.no = no;
        this.idx = idx;
    }
}

public class cses {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        ArrayList<Pair> ar = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            ar.add(new Pair(sc.nextInt(), i + 1));
        }
        
        ar.sort(Comparator.comparingInt((Pair p) -> p.no).thenComparingInt(p -> p.idx));
        
        for (int i = 0; i < n; i++) {
            int k = n - 1;
            for (int j = i + 1; j < n; j++) {
                int rem = x - (ar.get(i).no + ar.get(j).no);

                while (k > j && ar.get(k).no > rem) {
                    k--;          
                }
                
                if (k > j && k < n && ar.get(k).no == rem) {
                    System.out.println(ar.get(i).idx + " " + ar.get(j).idx + " " + ar.get(k).idx);
                    return;
                }
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
