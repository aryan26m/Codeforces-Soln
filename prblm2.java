import java.util.Scanner;

public class prblm2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int a = ask(1, 1, sc); 
            //! at least one of the mines lie on the diagonal given by the equation x + y = a + 2

            //* now finding the two endpoints of the diagonal
            //* perform casework on pen-paper to understand why this works

            int xd1 = Math.max(1, a + 2 - m);
            int yd1 = a + 2 - xd1;
            int yd2 = Math.max(1, a + 2 - n);
            int xd2 = a + 2 - yd2;

            //* query from both the endpoints
            int ad1 = ask(xd1, yd1, sc);
            int ad2 = ask(xd2, yd2, sc);

            //* check if either of them is equal to 0, in which case that point is a mine
            if (ad1 == 0) {
                tell(xd1, yd1);
                continue;
            }

            if (ad2 == 0) {
                tell(xd2, yd2);
                continue;
            }

            //* calculate the coordinates of the points based on their distance from the given endpoints of diagonal

            int xp1 = xd1 + (ad1 / 2);
            int yp1 = yd1 - (ad1 / 2);
            int xp2 = xd2 - (ad2 / 2);
            int yp2 = yd2 + (ad2 / 2);

            //* at least one of them should return 0 distance when queried
            if (ask(xp1, yp1, sc) == 0) {
                tell(xp1, yp1);
            } else {
                tell(xp2, yp2);
            }
        }

        sc.close();
    }

    static int ask(int x, int y, Scanner sc) {
        System.out.println("? " + x + " " + y);
        return sc.nextInt();
    }

    static void tell(int x, int y) {
        System.out.println("! " + x + " " + y);
    }
}
