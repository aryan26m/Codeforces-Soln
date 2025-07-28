import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class D_Counting_Pairs {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(reader.readLine());

        while (testCases-- > 0) {
            String[] firstLine = reader.readLine().split(" ");
            long arraySize = Long.parseLong(firstLine[0]);
            long lowerBound = Long.parseLong(firstLine[1]);
            long upperBound = Long.parseLong(firstLine[2]);

            long[] numbers = new long[(int) arraySize];
            long totalSum = 0;

            String[] inputNumbers = reader.readLine().split(" ");
            for (int i = 0; i < arraySize; i++) {
                numbers[i] = Long.parseLong(inputNumbers[i]);
                totalSum += numbers[i];
            }

            long minSum = Math.min(totalSum - lowerBound, totalSum - upperBound);
            long maxSum = Math.max(totalSum - upperBound, totalSum - lowerBound);
            Arrays.sort(numbers);
            long validPairsCount = 0;

            for (int i = 0; i < arraySize; i++) {
                long currentElement = numbers[i];
                if (currentElement > maxSum) {
                    break;     }

               int startIndex = i + 1, endIndex = (int) arraySize - 1;
                int firstValidIndex = -1;

                while (startIndex <= endIndex) {
                    int midIndex = startIndex + (endIndex - startIndex) / 2;
                    if (currentElement + numbers[midIndex] >= minSum) {
                        firstValidIndex = midIndex; // Found a valid index
                        endIndex = midIndex - 1; // Look for an earlier index
                    } else {
                        startIndex = midIndex + 1; // Move right
                    }
                }

                startIndex = i + 1;
                endIndex = (int) arraySize - 1;
                int lastValidIndex = -1;

                while (startIndex <= endIndex) {
                    int midIndex = startIndex + (endIndex - startIndex) / 2;
                    if (currentElement + numbers[midIndex] <= maxSum) {
                        lastValidIndex = midIndex; // Found a valid index
                        startIndex = midIndex + 1; // Look for a later index
                    } else {
                        endIndex = midIndex - 1; // Move left
                    }
                }

                if (firstValidIndex != -1 && lastValidIndex != -1 && firstValidIndex <= lastValidIndex) {
                    validPairsCount += (lastValidIndex - firstValidIndex + 1);
                }
            }

            System.out.println(validPairsCount);
        }
    }
}