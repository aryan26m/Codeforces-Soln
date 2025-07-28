#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << "NO\n";
        return;
    }
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i=0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> c(n);
    for(ll i=0; i < n; i++) {
        c[i] = lcm(a[i], b[i]);
    }
    vector<ll> prefix(n), suffix(n);
    prefix[0] = c[0];
    for(ll i = 1; i < n; i++) {
        prefix[i] = gcd(prefix[i - 1], c[i]);
    }

    suffix[n - 1] = c[n - 1];
    for(ll i = n - 2; i >= 0; i--) {
        suffix[i] = gcd(suffix[i + 1], c[i]);
    }

    bool check = true;
    for(ll i = 0; i < n; i++) {
        if (prefix[i] != a[i]) {
            check = false;
            break;
        }
    }
    for(ll i = 0; i < n; i++) {
        if (suffix[i] != b[i]) {
            check = false;
            break;
        }
    }
    cout << (check ? "YES\n" : "NO\n");

}

int main() {

    ll t;
    cin>>t;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}
