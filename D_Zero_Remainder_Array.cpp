#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
   map<ll, ll> freq;
    for(int i=0;i<n;i++){
        ll x=v[i]%k;
        if(x>0){
            freq[x]++;
        }
    }
   ll mx=0;
   ll rem=0;
    for(auto it: freq){
        ll x=it.first;
        ll y=it.second;
        if(y>mx){
            mx=y;
           rem=x;
        }
   }
   if(mx==0){
         cout << 0 << endl;
         return;
   }
   else{
      ll ans = (mx - 1) * k + (k-rem+1);
    cout << ans << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
