#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i % 2) v[i] = -v[i];
    }

    set<ll> seen;
    ll sum = 0;
    seen.insert(0);
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (seen.count(sum)) {
            cout << "YES\n";
            return 0;
        }
        seen.insert(sum);
    }
    cout << "NO\n";
    return 0;
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
