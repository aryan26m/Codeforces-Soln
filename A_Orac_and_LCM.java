import static java.lang.System.in;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A_Orac_and_LCM {
    static int N = 200001; // Adjust as needed
    static int[] spf = new int[N]; // Smallest prime factor

    static void sieve() {
        for (int i = 1; i < N; i++) spf[i] = i;

        for (int i = 2; i < N; i++) {
            for (int j = 2 * i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    static long power(int a, int b) {
        long res = 1;

        while (b > 0) {
            if ((b & 1) == 1) res *= a;
            a *= a;
            b >>= 1;
        }

        return res;
    }

    public static void main(String[] args) {
        sieve();
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        List<Integer>[] alist = new ArrayList[N];
        for (int i = 0; i < N; i++) alist[i] = new ArrayList<>();

        for (int i : a) {
            while (i != 1) {
                int p = spf[i], count = 0;
                while (i % p == 0) {
                    i /= p;
                    count++;
                }
                alist[p].add(count);
            }
        }

        long ans = 1;
        
        for (int i = 1; i < N; i++) {
            Collections.sort(alist[i]);
            if (alist[i].size() < n - 1) continue;
            else {
                if (alist[i].size() == n) ans *= power(i, alist[i].get(1));
                else ans *= power(i, alist[i].get(0));
            }
        }

        System.out.println(ans);
    }
}
