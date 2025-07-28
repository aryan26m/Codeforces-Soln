import java.util.Scanner;

public class A_Looped_Playlist {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        long totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += a[i];
        }
    
           long temp= k/totalSum;
            long newk=k%totalSum;

            int l = 0;
            long sum = 0;
            long minLength = Long.MAX_VALUE;
            int startIndex = -1;

            for (int r = 0; r < 2*n; r++) {
                sum += a[r % n];
                while (sum >= newk) {
                    if (r - l + 1 < minLength) {
                        minLength = r - l + 1;
                        startIndex = l % n;
                    }
                    sum-=a[l % n];
                    l++;
                }
            }
                System.out.println((startIndex + 1) + " " + ((temp*n)+minLength));
      
        sc.close();
    }
}