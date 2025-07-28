
    #include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 100000;
void solve(vector<vector<int>> &factors) {
    ll n;
    cin >> n;
    vector<ll> v(n);
    v.push_back(0); // to make it 1-indexed
    for(ll i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    vector<ll>ans(n+1,1);
    ans[0] = 0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        for(int x : factors[i]){
            if(v[i]>v[x]){
                ans[i]=max(ans[i],ans[x]+1);
            }
        }
    }
    ll mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,ans[i]);
    }
    cout<<mx<<endl;


    // cout << mx << endl;
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> factors(MAX + 1);
     for (int i = 1; i <= MAX; ++i) {
         for (int j = i; j <= MAX; j += i) {
             factors[j].push_back(i);
         }
     }
    while (t--) {
        solve(factors);
    }
    return 0;
}
