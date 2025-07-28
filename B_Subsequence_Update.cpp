#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> v(n);
        for(ll i = 0; i < n; i++) cin >> v[i];

        ll sum = 0;
        for(ll i = l-1; i < r; i++) sum += v[i];

        vector<ll> a(v.begin() + l - 1, v.begin() + r);
        sort(a.begin(), a.end());

        ll lsum = accumulate(a.begin(), a.end(), 0LL);

        vector<ll> b(v.begin(), v.begin() + r);
        sort(b.begin(), b.end());

        ll rsum = accumulate(b.begin(), b.begin() + (r - l + 1), 0LL);

        ll last = min({sum, lsum, rsum});
        cout << last << endl;
    }
    return 0;
}