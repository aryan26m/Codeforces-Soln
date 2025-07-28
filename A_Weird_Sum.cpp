#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    
    ll n,m;
    
    cin >> n >> m;

    ll v[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
      }
    
    unordered_map <ll,vector<pair<ll,ll>>> mp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         ll x=v[i][j];
         mp[x].push_back({i,j});
        }
    }
    ll ans=0;
    for(auto it:mp){
        vector<pair<ll,ll>> temp=it.second;
        vector <ll> x;
        vector <ll> y;
        for(int i=0;i<temp.size();i++){
            x.push_back(temp[i].first);
            y.push_back(temp[i].second);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        ll sum1=0;
        for(int i=0;i<x.size();i++){
            sum1+=x[i];
        }
        for(int i=0;i<x.size();i++){
            sum1-=x[i];
            ll temp1=x.size()-i-1;
            ans+=sum1-temp1*x[i];
        }
        ll sum2=0;
        for(int i=0;i<y.size();i++){
            sum2+=y[i];
        }
        for(int i=0;i<y.size();i++){
            sum2-=y[i];
            ll temp1=y.size()-i-1;
            ans+=sum2-temp1*y[i];
        }
    }
    cout<<ans<<endl;
}

int main() {

    solve();

    return 0;
}

