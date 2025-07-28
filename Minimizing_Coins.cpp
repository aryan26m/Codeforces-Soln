#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
    ll n,k;
    cin>>n>>k;
    
    vector <ll> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    vector<ll> dp(k+1,INT_MAX);
    // sort(v.begin(),v.end());
    dp[0]=0;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i>=v[j]){
                dp[i]=min(dp[i],1 + dp[i-v[j]]);
            }
        }
    }

    if(dp[k]>=INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[k]<<endl;

    }
        }

int main(){
   solve();
}