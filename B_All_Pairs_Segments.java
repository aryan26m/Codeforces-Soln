import java.util.*;

public class B_All_Pairs_Segments {

    static Scanner sc = new Scanner(System.in);

    // Template function to join elements of a list with a delimiter
    public static <T> String join(List<T> list, String delimiter) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < list.size(); i++) {
            result.append(list.get(i));
            if (i < list.size() - 1) {
                result.append(delimiter);
            }
        }
        return result.toString();
    }

    // Process each test case
    public static String processTestCase(int numElements, int numQueries, List<Integer> elements, List<Integer> queries) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int currentPos = 0; currentPos < numElements; currentPos++) {
            int kPos = currentPos * (numElements - currentPos);
            frequencyMap.put(kPos, frequencyMap.getOrDefault(kPos, 0) + 1);

            if (currentPos < numElements - 1) {
                int delta = elements.get(currentPos + 1) - elements.get(currentPos) - 1;
                if (delta > 0) {
                    int kBetween = (currentPos + 1) * (numElements - currentPos - 1);
                    frequencyMap.put(kBetween, frequencyMap.getOrDefault(kBetween, 0) + delta);
                }
            }
        }
        List<String> results = new ArrayList<>();
        for (int query : queries) {
            results.add(String.valueOf(frequencyMap.getOrDefault(query, 0)));
        }
        return join(results, " ");
    }

    public static void main(String[] args) {

        int numTestCases = sc.nextInt();
        List<String> testCaseResults = new ArrayList<>();

        for (int i = 0; i < numTestCases; i++) {
            int numElements = sc.nextInt();
            int numQueries = sc.nextInt();

            List<Integer> elements = new ArrayList<>();
            for (int j = 0; j < numElements; j++) {
                elements.add(sc.nextInt());
            }

            List<Integer> queries = new ArrayList<>();
            for (int j = 0; j < numQueries; j++) {
                queries.add(sc.nextInt());
            }

            // Process the current test case and store the result
            String result = processTestCase(numElements, numQueries, elements, queries);
            testCaseResults.add(result);
        }

        // Print all test case results joined by newline
        System.out.println(join(testCaseResults, "\n"));
    }
}
