#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> v, c;

void precompute() {
    v.push_back(1);
    while (v.back() * 3 <= 1e9)
        v.push_back(v.back() * 3);
    int m = (int)v.size();
    c.resize(m);
    c[0] = 3;
    for (int i = 1; i < m; i++) {
        c[i] = 3 * v[i] + i * (v[i] / 3);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> d;
        int tmp = n;
        int s = 0;
        while (tmp > 0) {
            int digit = tmp % 3;
            d.push_back(digit);
            s += digit;
            tmp /= 3;
        }
        if (s > k) {
            cout << -1 << "\n";
            continue;
        }

        int m = k;
        if ((m - s) % 2 != 0)
            m--;
        m = min(m, n);

        int ans = 0;
        for (int i = 0; i < (int)d.size(); i++) {
            ans += d[i] * c[i];
        }

        int cnter = (m - s) / 2;

        for (int i = (int)d.size() - 1; i >= 1 && cnter > 0; i--) {
            if (d[i] == 0) continue;
            int can = min(d[i], cnter);
            ans -= can * v[i - 1]; 
            d[i] -= can;
            d[i - 1] += 3 * can;
            cnter -= can;
        }

        cout << ans << "\n";
    }

    return 0;
}
