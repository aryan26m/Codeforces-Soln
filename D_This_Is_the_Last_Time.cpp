#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,k;
    cin >> n >> k;
    vector <pair<pair<ll,ll>,ll>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    sort(v.begin(),v.end());
    ll x=v.size();
    ll ans=0;
    for(int i=0;i<n;i++){
        if(v[i].first.first <= k){
            if(v[i].second >= k){
                ans = max(ans, v[i].second);
                k= v[i].second;
            }
        }
        else{
            break;
        }
    }
    ans=max(ans,k);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
