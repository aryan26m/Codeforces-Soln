#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,x,k;
    cin >>n>>x>>k;
    pair <ll,ll> range={0ll,0ll};
    for(int i=0;i<k;i++){
        ll a;
        ll b;
        cin>>a;
        cin>>b;
        if(a<=x && b>=x && range.first==0ll && range.second==0ll){
            range.first=a;
            range.second=b;
        }
        else if(range.first!=0ll && range.second!=0ll){
            if(a<=range.second && b>=range.first){
                range.first=min(range.first,a);
                range.second=max(range.second,b);
            }
        }
    }
    ll ans=(range.second-range.first)+1;
    cout<<ans<<endl;
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
