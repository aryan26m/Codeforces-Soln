#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> h1(n);
    vector<ll> h2(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h1[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> h2[i];
    }
    ll dp[n][2];
    dp[0][0] = h1[0];
    dp[0][1] = h2[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][1]+h1[i],dp[i-1][0]);
        dp[i][1]=max(dp[i-1][0]+h2[i],dp[i-1][1]);
        }
    ll ans = max(dp[n-1][0], dp[n-1][1]);
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
