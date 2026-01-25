#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int bal = 0;
        bool ok = false;

        // count total closing brackets
        int totalClose = n / 2;
        int usedClose = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
                usedClose++;

                // key condition
                if (bal >= 1 && usedClose < totalClose) {
                    ok = true;
                    break;
                }
            }
        }

        if (ok) cout << n - 2 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
