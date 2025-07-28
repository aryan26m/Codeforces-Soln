#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n), p(n);
    map<ll, vector<ll>> dp;

    for(ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 0; i < n; i++) {
        cin >> p[i];
        dp[v[i]].push_back(p[i]);
    }
    vector<ll> ans(n + 1, 0); // ans[k] = max sum for k

    for (auto& it : dp) {
        vector<ll>& temp = it.second;
        sort(temp.rbegin(), temp.rend()); // sort descending

        int sz = temp.size();
        vector<ll> prefix(sz + 1, 0); // prefix sums
        for (int i = 0; i < sz; i++) {
            prefix[i + 1] = prefix[i] + temp[i];
        }
        for (int k = 1; k <= sz; k++) {
            int complete = sz / k;
            ans[k] += prefix[complete * k]; // only full groups
        }
    }

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}