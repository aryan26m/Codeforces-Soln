#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    } 
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(65, vector<int>(65, -1)));
    auto f=[&](int index,int AND,int last,auto &&f)->int{
        if(index==n){
            if(AND==0) return 1ll;
            else return 0ll;
        }
        if(dp[index][AND][last]!=-1) return dp[index][AND][last];
        // take 
        int ans=0;
        if(a[index]>=last) ans+=f(index+1,AND&a[index],a[index],f);
        // not take 
        ans+=f(index+1,AND,last,f);
        return dp[index][AND][last]=ans;
    };
    cout<<f(0,63,0,f)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc=1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}