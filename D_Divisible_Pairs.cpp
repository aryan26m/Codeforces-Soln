#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
ll solve() {
    int n; 
    ll x,y;
    cin>>n>>x>>y;
    vector <ll> v;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    map<pair<ll ,ll>,ll> mp;
    ll ans=0;
    for(int i=0;i<n;i++){
    ll x1=v[i]%x;
        ll y1=v[i]%y;
        ll req=(x-x1)%x;
        ll req2=y1;
        ans+=mp[{req,req2}];
        mp[{x1,y1}]++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
