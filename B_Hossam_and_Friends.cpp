#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0);
    
    for(int i=0;i<k;i++){
        ll x,y;
        cin >> x >> y;
        if(x > y) swap(x,y);
        a[y]=max(a[y],x);
    }
    ll ans=0;
    ll maxi=0;
    for(ll i=1;i<=n;i++){
        maxi=max(maxi,a[i]);
        ans+=i-maxi;
    }
    cout<<ans<<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}