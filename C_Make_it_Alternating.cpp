#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 998244353;

// Precompute factorials up to a reasonable limit
const int MAXN = 2e5 + 5;
vector<ll> fact(MAXN);

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int solve() {
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0;
    vector <int> v;
    int cnt=1;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        else{
            v.push_back(cnt);
            cnt=1;
        }
    }
    v.push_back(cnt);
    ll total=1;
    for (int i = 0; i < v.size() ; i++) {
      ans+=(v[i]-1);
    }
    for (int i = 0; i < v.size() ; i++) { 
        total=(total*v[i])%mod;
    }
    long fac=fact[ans];
    long mainans=(total*fac)%mod;
    cout << ans << " " <<mainans << endl;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials(); // Call once before test cases

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
