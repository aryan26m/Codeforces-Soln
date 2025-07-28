import java.util.Scanner;

public class A_Shape_Perimeter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        for (int i = 0; i < testCases; i++) {
            int operations = scanner.nextInt();
            int stampSize = scanner.nextInt();
            int[][] moves = new int[operations][2];
            for (int j = 0; j < operations; j++) {
                moves[j][0] = scanner.nextInt();
                moves[j][1] = scanner.nextInt();
            }
            long per = calculatePerimeter(operations, stampSize, moves);
            System.out.println(per);
        }
        scanner.close();
    }

    private static long calculatePerimeter(int operations, int stampSize, int[][] moves) {
        long per = 4 * stampSize;
        for (int i = 1; i < operations; i++) {
            per += (4 * stampSize - (2 * ((stampSize - moves[i][0]) + (stampSize - moves[i][1]))));
        }
        return per;
    }
}
