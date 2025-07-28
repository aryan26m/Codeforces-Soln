#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
    ll n;
    cin>>n;
    ll dp[n+1];
    dp[0]=1;
    ll mod=1e9+7;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=6;j++){
            if(i>=j){
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
    }
   cout<<dp[n]<<endl;
        }

int main(){
   solve();
}