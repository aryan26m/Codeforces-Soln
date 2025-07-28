import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCases = Integer.parseInt(br.readLine().trim());
        while (testCases-- > 0) {
            int length = Integer.parseInt(br.readLine().trim());
            StringBuilder result = new StringBuilder();
            result.append("1 ");
            for (int i = 2; i <= length - 2; i++) {
                result.append(i - 1).append(" ");
            }
            result.append("1 2\n");
            bw.write(result.toString());
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
