import java.util.Scanner;

public class A_Get_together {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        double[][] arr = new double[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = sc.nextDouble();
            arr[i][1] = sc.nextDouble();
        }

        double l = 0;
        double h = 1e9;
        for (int i = 0; i < 50; i++) {
            double mid = (l + h) / 2;
            if (predicate(arr, mid, n)) {
                h = mid;
            } else {
                l = mid;
            }
        }
        System.out.printf("%.6f\n", h); // Set precision for output
    }

    public static boolean predicate(double[][] arr, double mid, int n) {
        double maxpos = 1e18;
        double minpos = -1e18;
        for (int i = 0; i < n; i++) {
            minpos = Math.max(minpos, arr[i][0] - (arr[i][1] * mid));
            maxpos = Math.min(maxpos, arr[i][0] + (arr[i][1] * mid));
            if (maxpos < minpos) {
                return false;
            }
        }
        return true;
    }
}
