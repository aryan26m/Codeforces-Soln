#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const long long INF = 1e18;

    long long a = INF, b = INF, c = INF;
    long long ab = INF, ac = INF, bc = INF;
    long long abc = INF;

    for (int i = 0; i < n; i++) {
        long long cost;
        string s;
        cin >> cost >> s;

        bool A = false, B = false, C = false;
        for (char ch : s) {
            if (ch == 'A') A = true;
            if (ch == 'B') B = true;
            if (ch == 'C') C = true;
        }

        if (A) a = min(a, cost);
        if (B) b = min(b, cost);
        if (C) c = min(c, cost);

        if (A && B) ab = min(ab, cost);
        if (A && C) ac = min(ac, cost);
        if (B && C) bc = min(bc, cost);

        if (A && B && C) abc = min(abc, cost);
    }

    long long ans = INF;

    ans = min(ans, abc);
    ans = min(ans, ab + c);
    ans = min(ans, ac + b);
    ans = min(ans, bc + a);
    ans = min(ans, a + b + c);

    if (ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
