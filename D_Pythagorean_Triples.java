import static java.lang.Math.sqrt;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

public class D_Pythagorean_Triples {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // pre();
        
        int t = sc.nextInt();
        while (t-- >0) {
            long ans=0;
            long n=sc.nextLong();
            long s=(long)sqrt((2*n)-1);
           for(int a=1;a<=s;a+=2){
                   long b= ((a*a)-1)/2;
                   if (a<=b) {
                    ans++;
                   }
           }
           System.out.println(ans);
        }
        sc.close();
    }
}
