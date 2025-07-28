#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> get_factors(int x) {
    vector<int> factors;
    for (int i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }
    if (x > 1) factors.push_back(x);
    return factors;
}

int solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

   unordered_map<int , int> mp;
    for(int i=0;i<n;i++){
    int x=v[i];
         for (int j = 2; j * j <= x; ++j) {
        while (x % j == 0) {
            mp[j]++;
            x /= j;
        }
    }
    if (x > 1) mp[x]++;
    }
    for(auto it : mp){
        if((it.second%n)!=0 && it.first!=1){
            cout<<"NO"<<endl;
         return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
