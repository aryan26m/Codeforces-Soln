#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x : v) cin >> x;

    ll even = 1, odd = 0;
    ll neg = 0;
    ll posProd = 0, negProd = 0;
    for (ll i = 0; i < n; ++i) {
        if (v[i] < 0) neg ^= 1;
        if (neg == 0) {
            posProd += even;
            negProd += odd;
            even++;
        } else {
            posProd += odd;
            negProd += even;
            odd++;
        }
    }
    cout << negProd << " " << posProd << endl;
}

int main() {
    solve();
    return 0;
}
