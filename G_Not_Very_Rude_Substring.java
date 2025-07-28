import java.util.Scanner;

public class G_Not_Very_Rude_Substring {
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         long n = sc.nextLong();
         long k = sc.nextLong();
         String s = sc.next();
         char[] ch = s.toCharArray();
         long ans = 0;
         long acount = 0;
         long bcount = 0;
         long rud = 0;
         for(long l = 0, r = 0; r < n; r++){
            if(ch[(int)r] == 'a'){
                acount++;
            }
            if(ch[(int)r] == 'b'){
                bcount++;
                rud += acount;
            }
            while (rud > k && l < n) {
                if (ch[(int)l] == 'a') {
                    acount--;
                }
                if (ch[(int)l] == 'b') {
                    bcount--;
                }
                if (ch[(int)l] == 'a') {
                    rud -= bcount;
                }
                l++;
            }
            ans = Math.max(ans, r - l + 1);
         }
         System.out.println(ans);
         sc.close();
    }
}
