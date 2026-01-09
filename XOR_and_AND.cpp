#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(NULL)

const int MOD = 1e9 + 7;

int n;
vector<int> v;
int power(int a, int b, int mod = MOD){
    int res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int allPairXor(){
    int ans = 0;
    for(int i = 0; i < 31; i++){
        int cnt1 = 0;
        for(int j = 0; j < n; j++){
            if((v[j] >> i) & 1) cnt1++;
        }
        int cnt0 = n - cnt1;
        ans = (ans + (cnt0 * cnt1 % MOD) * (1LL << i)) % MOD;
    }
    return ans;
}

int allPairAnd(){
    int ans = 0;
    for(int i = 0; i < 31; i++){
        int cnt1 = 0;
        for(int j = 0; j < n; j++){
            if(v[j] & (1LL << i)) cnt1++;
        }
        int pairs = cnt1 * (cnt1 - 1) / 2;
        ans = (ans + (pairs % MOD) * (1LL << i)) % MOD;
    }
    return ans;
}
int allSubsetXor(){
    int OR = 0;
    for(int x : v) OR |= x;
    return OR * power(2, n - 1) % MOD;
}

int allSubsetAnd(){
    int ans = 0;
    for(int i = 0; i < 31; i++){
        int cnt1 = 0;
        for(int j = 0; j < n; j++){
            if((v[j] >> i) & 1) cnt1++;
        }
        if(cnt1 > 0){
            int ways = (power(2, cnt1) - 1 + MOD) % MOD;
            ans = (ans + ways * (1LL << i)) % MOD;
        }
    }
    return ans;
}

void solve(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << allPairXor() << " "
         << allSubsetXor() << " "
         << allPairAnd() << " "
         << allSubsetAnd() << "\n";
}

int32_t main(){
    fast;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
