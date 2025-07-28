#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);

    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < m; ++i)
        cin >> b[i];

    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
        return;
    }

    sort(b.begin(), b.end());
    ll mx = b.back();  
    a[0] = min(a[0], mx - a[0]);

    for (ll i = 1; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
        if (it == b.end() && a[i] < a[i - 1]) {
            cout << "NO\n";
            return;
        }
        if (it != b.end() && (*it) - a[i] >= a[i - 1]) {
            a[i] = (*it) - a[i];
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
