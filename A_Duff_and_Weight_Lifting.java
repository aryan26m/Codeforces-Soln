import java.io.*;

public class A_Duff_and_Weight_Lifting {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine()); // Number of integers
        int limit = (int) 1e7;
        int[] a = new int[limit];

        // Read all integers in one line
        String[] inputs = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(inputs[i]);
            a[x]++;
        }

        int ans = 0;
        for (int i = 0; i+1<limit; i++) {
            a[i + 1] += a[i] / 2;  // Transfer pairs to the next index
            a[i] %= 2;            // Keep only the remaining single element
            ans += a[i];          // Add the singles to the answer
        }

        bw.write(ans + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}