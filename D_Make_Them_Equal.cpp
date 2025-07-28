#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int,int>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define fast ios::sync_with_stdio(false); cin.tie(0);
const int MOD = 1e9 + 7;
const int INF = 1e18;
int N = 1001;
vector<int> dp(N, INF);
void precompute_dp() {
    dp[1] = 0;
    for (int p = 1; p < N; p++) {
        for (int q = 1; q <= p; q++) {
            int idx = p + p / q;
            if (idx < N) {
                dp[idx] = min(dp[idx], dp[p] + 1);
            }
        }
    }
}
void solve(){
int n,k;
cin>>n>>k;
k=min(k, 12*n); // Ensure k does not exceed the precomputed range
vector<int> v(n);
vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    vector<int> preq(k+1,0);
    // cout<<":DFAEFAEFE";
    for(int i=1;i<=n;i++){
        vector<int> cur(k+1,0);
        for(int j=0;j<=k;j++)
        {
            int cot = dp[v[i-1]];
            int val=c[i-1];
             int pick=0;
            if(j>=cot){
                pick=preq[j-cot]+val;
            }
            int notpick=preq[j];;
            cur[j]=max(pick, notpick);
        }
        preq=cur;
    }
   cout<<preq[k]<<endl;

}
// Solve Function
int32_t main() {
    fast;
    precompute_dp();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
   