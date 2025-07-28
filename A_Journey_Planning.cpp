#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    unordered_map<ll, ll> groupSum;
    ll mx = 0;

    for (ll i = 0; i < n; ++i) {
        ll key = v[i] - i;
        groupSum[key] += v[i];
        mx = max(mx, groupSum[key]);
    }

    cout << mx << endl;
}

int main() {
    solve();
    return 0;
}