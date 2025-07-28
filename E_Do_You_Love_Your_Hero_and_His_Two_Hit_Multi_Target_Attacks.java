import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.*;

/**
 * template
 */
public class E_Do_You_Love_Your_Hero_and_His_Two_Hit_Multi_Target_Attacks {
    static Scanner sc = new Scanner(System.in); // Declare Scanner as static
  

    public static void main(String[] args) {
        int t=sc.nextInt();
        while(t-- >0) {
            long n=sc.nextLong();
        ArrayList <Pair> arr=new ArrayList<Pair>();
        long cntx=0;
        long cnty=0;
        while (n>0) {
            long s=searchLong(n);
            for(long i=0;i<s;i++){
                arr.add(new Pair(cntx,cnty++));
            }
            cntx++;
            n-=s*(s-1)/2;
        }
        System.out.println(arr.size());
        for(Pair x :arr){
            System.out.println(x.x+" "+x.y);
        }
    }

}
public static long searchLong(long k) {
    long l = 0, r = 500;
    while (l < r) {
        long mid = (l + r + 1) / 2;
        if (mid * (mid - 1) / 2 > k) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}
}
class Pair{
    long x;
    long y;
    Pair(long x,long y){
        this.x=x;
        this.y=y;
    }
}