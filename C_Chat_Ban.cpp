#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve() {
    ll k, x;
    cin >> k >> x;
    ll ans = 2 * k - 1;
    ll l = 1;
    ll h = 2 * k - 1;
    while (l <= h) {
        ll mid = (l + h) / 2;
        ll total = 0;
        if (mid <= k) {
            total = (mid * (mid + 1)) / 2;
        } else {
            total = (k * (k + 1)) / 2;
            ll left = (2 * k - 1) - mid;
            total += (k * (k - 1)) / 2 - (left * (left + 1)) / 2;
        }

        if (total >= x) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

int main() {
    ll t;
    cin >> t;
    while (t--) { solve(); }
}
