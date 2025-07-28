import java.io.*;
import java.util.*;

public class B_Array_merging {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve(br, bw);
        }

        bw.flush();
        bw.close();
    }

    static void solve(BufferedReader br, BufferedWriter bw) throws IOException {
        int n = Integer.parseInt(br.readLine());
        String[] inputA = br.readLine().split(" ");
        String[] inputB = br.readLine().split(" ");

        int[] A = new int[n];
        int[] B = new int[n];
        Set<Integer> elements = new HashSet<>();

        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(inputA[i]);
            elements.add(A[i]);
        }

        for (int i = 0; i < n; i++) {
            B[i] = Integer.parseInt(inputB[i]);
            elements.add(B[i]);
        }

        Map<Integer, Integer> mp1 = new HashMap<>();
        Map<Integer, Integer> mp2 = new HashMap<>();
        int cnt = 1;
        mp1.put(A[0], 1);

        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            mp1.put(A[i], Math.max(mp1.getOrDefault(A[i], 0), cnt));
        }

        cnt = 1;
        mp2.put(B[0], 1);
        for (int i = 1; i < n; i++) {
            if (B[i] == B[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            mp2.put(B[i], Math.max(mp2.getOrDefault(B[i], 0), cnt));
        }

        int ans = 1;
        for (int e : elements) {
            ans = Math.max(ans, mp1.getOrDefault(e, 0) + mp2.getOrDefault(e, 0));
        }

        bw.write(ans + "\n");
    }
}