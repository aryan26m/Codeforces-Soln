import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class A_Jellyfish_and_Undertale {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long limit = sc.nextLong();
            long start = sc.nextLong();
            int n = sc.nextInt();
            ArrayList<Long> ar = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                ar.add(sc.nextLong());
            }
        
            long count=start-1;

            for(int i=0;i<n-1;i++){
                if ((1+ar.get(i))<limit) {
                    start=1+ar.get(i);
                }
                else{
                    start=limit;
                }
                count+=start-1;
            }

            if ((1+ar.get(n-1))<limit) {
                start=1+ar.get(n-1);
                count+=start;
            }
            else{
                start=limit;
                count+=start;
            }

            System.out.println(count);
        }
    }
}
