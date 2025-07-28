import java.util.Scanner;

public class A_Exciting_Bets {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        while (t-- > 0) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long diff = Math.abs(a - b);
            if (diff == 0) {
                System.out.println("0 0");
                continue;
            }
            long miner =Math.min(a, b);
            long ans1=miner%diff;
            long ans2=diff-(miner%diff);
            


            // long ans2=
            System.out.println(diff + " " +Math.min(ans1, ans2));
        }
    }
}