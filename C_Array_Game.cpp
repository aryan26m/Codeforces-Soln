#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> v;
    ll minn=LONG_LONG_MAX;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
        minn = min(minn, x);
    }
    sort(v.begin(), v.end());
    if(k==1){
        ll minner = LONG_LONG_MAX;
        for(ll i = 0; i < n-1; i++) {
            minner = min(minner, v[i+1] - v[i]);
    
        }
            minn =  min(minn, minner);
        cout<<minn<<endl;
    }
    else if(k==2){
        for(int i = 0; i < n - 1; i++) {
            minn=min(minn, abs(v[i+1] - v[i]));
            for(int j = i + 1; j < n; j++) { 
                ll x =abs(v[j] - v[i]);
                auto it = lower_bound(v.begin(), v.end(), x);
                if(it != v.end()) {
                    int idx = it - v.begin();
                    ll minner = abs(x - v[idx]);
                    minn = min(minn, minner);
                    if(idx > 0){
                        ll minner2 = abs(x - v[idx-1]);
                        minn = min(minn, minner2);
                    }
                }
                else{
                    ll minner = abs(x - v[n-1]);
                    minn = min(minn, minner);
                }
            }
        }
        cout << minn << endl;
    }
    else{
        cout << 0 << endl;
}
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}