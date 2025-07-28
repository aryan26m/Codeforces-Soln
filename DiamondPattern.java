public class DiamondPattern {
    public static void main(String[] args) {
        int n = 4;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        System.out.print(" ");
    }
    for (int j = 0; j <= i; j++) {
        System.out.print("X ");
    }
    System.out.println();
}

for (int i = n; i > 0; i--) {
    for (int j = 0; j < n - i; j++) {
        System.out.print(" ");
    }
    for (int j = 0; j < i; j++) {
        System.out.print("X ");
    }
    System.out.println();
}


    }
}
    