#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<long long, int> m;
    for (int i = 0; i < n; ++i) {
        long long t;
        cin >> t;
        m[t]++;
    }

    vector<long long> v;
    for (auto const& [l, c] : m) {
        v.push_back(l);
    }

    long long r = 0;
    long long s = 0;
    long long a = 0;
    long long b = 0;

    for (long long x : v) {
        int k = m[x];

        if (k >= 2) {
            long long p = k / 2;
            long long y = s + p * 2 * x;

            long long c = a;
            long long d = b;

            if (k % 2 == 1) {
                if (x > c) {
                    d = c;
                    c = x;
                } else if (x > d) {
                    d = x;
                }
            }

            if (2 * x < y) r = max(r, y);
            if (c > 0) {
                long long z = y + c;
                if (2 * x < z) r = max(r, z);
            }
            if (d > 0) {
                long long z = y + c + d;
                if (2 * x < z) r = max(r, z);
            }
        }

        if (k >= 1) {
            long long y = s;
            if (y > 0) {
                long long z = y + x;
                if (2 * x < z) r = max(r, z);
            }
            if (a > 0) {
                long long z = y + x + a;
                if (2 * x < z) r = max(r, z);
            }
        }

        s += (long long)(k / 2) * 2 * x;
        if (k % 2 == 1) {
            if (x > a) {
                b = a;
                a = x;
            } else if (x > b) {
                b = x;
            }
        }
    }

    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
