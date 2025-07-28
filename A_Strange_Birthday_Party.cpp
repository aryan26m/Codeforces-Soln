#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(k+1);
    b[0]=0;
  for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 1; i <= k; ++i)
        cin >> b[i];

    sort(a.rbegin(),a.rend());
     vector <bool> check(n,true);
     int j=1;
     ll ans=0;
     for(int i=0;i<n;i++){
          if(b[a[i]]>b[j] && check[j]==true){
              ans+=b[j];
              check[j]=false;
              j++;
          }
          else{
            ans+=b[a[i]];
          }
          cout<<ans<<endl;
     }
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
