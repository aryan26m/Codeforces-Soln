#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(){
      ll n;
      cin>>n;
      vector <ll>v(n);
      for( ll i=0;i<n;i++)   {
        cin>>v[i];
      } 

    vector <pair<ll,ll>> ms;
    for(ll i=0;i<n;i++){
        if(v[i]<i+1){
            ms.push_back({v[i],i+1});
        }
    }

    ll ans=0;
    sort(ms.begin(),ms.end());
    for(int i=0;i<ms.size();i++){
          ll finder=ms[i].second;
          auto it = upper_bound(ms.begin(), ms.end(), make_pair(finder, 0LL),
                               [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
                                   return a.first < b.first;
                               });

                               ans+=ms.size() - (it-ms.begin());
                            }
                            cout<<ans<<endl;


}
 int main(){
    ll t;
    cin>>t;
    while(t--){solve();}
 }