import java.util.*;

public class C_Preparing_for_the_Exam {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();

        while (testCases-- > 0) {
            int dragonCount = scanner.nextInt();
            int firstGroupSize = scanner.nextInt();
            int secondGroupSize = scanner.nextInt();

            int[] firstGroup = new int[firstGroupSize];
            int[] secondGroup = new int[secondGroupSize];

            for (int i = 0; i < firstGroupSize; i++) {
                firstGroup[i] = scanner.nextInt();
            }

            for (int i = 0; i < secondGroupSize; i++) {
                secondGroup[i] = scanner.nextInt();
            }

            StringBuilder result = new StringBuilder();
            if (secondGroupSize == dragonCount) {
                char[] tempArray = new char[firstGroupSize];
                Arrays.fill(tempArray, '1');
                result.append(new String(tempArray));
            } else if (secondGroupSize == dragonCount - 1) {
                Arrays.sort(secondGroup);
                int missingNumber = 1;
                for (int num : secondGroup) {
                    if (num == missingNumber) {
                        missingNumber++;
                    } else {
                        break;
                    }
                }

                for (int i = 0; i < firstGroupSize; i++) {
                    if (firstGroup[i] == missingNumber) {
                        result.append('1');
                    } else {
                        result.append('0');
                    }
                }
            } else {
                char[] tempArray = new char[firstGroupSize];
                Arrays.fill(tempArray, '0');
                result.append(new String(tempArray));
            }

            System.out.println(result.toString());
        }

        scanner.close();
    }
}
