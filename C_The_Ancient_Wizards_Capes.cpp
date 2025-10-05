#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Tcases;
    if (!(cin >> Tcases)) return 0;
    while (Tcases--) {
        int n;
        cin >> n;
        vector<long long> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<long long> c(n+1), beta(n+1);
        for (int i = 1; i <= n; ++i) {
            c[i] = a[i] - n + i - 1; // c_i
            beta[i] = c[i] - beta[i-1]; // beta recurrence
        }

        long long ans = 0;
        if (n % 2 == 0) {
            // n even -> T fixed
            long long Tfixed = beta[n];
            if (Tfixed < 0 || Tfixed > n) {
                ans = 0;
            } else {
                bool ok = true;
                for (int i = 1; i <= n && ok; ++i) {
                    long long Pi = (i % 2 ? Tfixed + beta[i] : beta[i]);
                    if (Pi < 0 || Pi > i) { ok = false; break; }
                    long long Pim1 = ( (i-1) % 2 ? Tfixed + beta[i-1] : beta[i-1] );
                    long long Li = Pi - Pim1;
                    if (Li != 0 && Li != 1) { ok = false; break; }
                }
                ans = ok ? 1 : 0;
            }
        } else {
            // n odd -> need beta[n] == 0, T variable
            if (beta[n] != 0) {
                ans = 0;
            } else {
                long long L = 0, R = n; // global T bounds
                bool ok = true;

                for (int i = 1; i <= n && ok; ++i) {
                    if (i % 2 == 0) {
                        // Even i: P_i = beta[i] independent of T
                        if (beta[i] < 0 || beta[i] > i) { ok = false; break; }
                        // L_i constraint: beta[i] - (T + beta[i-1]) in {0,1}
                        // => beta[i] - beta[i-1] - 1 <= T <= beta[i] - beta[i-1]
                        long long low = beta[i] - beta[i-1] - 1;
                        long long high = beta[i] - beta[i-1];
                        L = max(L, low);
                        R = min(R, high);
                    } else {
                        // Odd i: 0 <= T + beta[i] <= i
                        L = max(L, -beta[i]);
                        R = min(R, i - beta[i]);
                        // L_i constraint: (T + beta[i]) - beta[i-1] in {0,1}
                        // => beta[i-1] - beta[i] <= T <= beta[i-1] - beta[i] + 1
                        long long low = beta[i-1] - beta[i];
                        long long high = beta[i-1] - beta[i] + 1;
                        L = max(L, low);
                        R = min(R, high);
                    }
                    if (L > R) { ok = false; break; }
                }
                if (!ok) ans = 0;
                else {
                    // Clamp within [0, n]
                    L = max<long long>(L, 0);
                    R = min<long long>(R, n);
                    if (L > R) ans = 0;
                    else ans = (R - L + 1) % MOD;
                }
            }
        }

        cout << ans % MOD << "\n";
    }
    return 0;
}