#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a;
    a.push_back(k);
    for(ll i = 0; i < n-1; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    vector<ll> b;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    ll ans=0;
    ll i=0;
    ll j=0;
    while(i < n && j < n) {
        if(a[i] < b[j]) {
            j++;
            i++;
        }
        else{
            j++;
            ans++;
        }
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}