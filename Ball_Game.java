import java.util.*;

public class Ball_Game {
    // Helper class to store a pair of values
    static class Pair {
        long position, speed;

        Pair(long position, long speed) {
            this.position = position;
            this.speed = speed;
        }
    }

    // Function to solve each test case
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong(); // Read the value of n
        List<Pair> balls = new ArrayList<>();
        
        // Input the positions and speeds
        for (int i = 0; i < n; i++) {
            long position = sc.nextLong();
            balls.add(new Pair(position, 0));
        }
        for (int i = 0; i < n; i++) {
            long speed = sc.nextLong();
            balls.get(i).speed = speed;
        }

        // Sort the balls by their positions
        Collections.sort(balls, Comparator.comparingLong(a -> a.position));

        // Calculate the time for each ball to collide with other balls
        List<Double> time = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (balls.get(i).speed != 0) {
                time.add((double) balls.get(i).position / balls.get(i).speed);
            } else {
                time.add(Double.MAX_VALUE); // Infinite time for stationary balls
            }
        }

        // Count the valid times
        int count = 0;
        double minTime = Double.MAX_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            if (time.get(i) <= minTime) {
                count++;
            }
            minTime = Math.min(time.get(i), minTime);
        }

        System.out.println(count); // Output the result
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T_T = sc.nextInt(); // Number of test cases
        while (T_T-- > 0) {
            solve(); // Solve each test case
        }
    }
}
