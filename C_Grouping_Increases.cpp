#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <ll> x1;
    vector <ll> x2;
    x1.push_back(v[0]);
    for(ll i = 1; i < n; i++) {
        int p=x1.size();
        int q=x2.size();
        if(v[i]<=x1[p-1] && q==0) {
              x1.push_back(v[i]);
        }
        if(v[i]>x1[p-1] && q==0){
            x2.push_back(v[i]);
        }
        if(v[i]<=x1[p-1] && q>0 && v[i]<=x2[q-1]){
            if(x1[p-1]<x2[q-1]) {
                x1.push_back(v[i]);
            } else {
                x2.push_back(v[i]);
            }
        }
        else if(v[i]<=x1[p-1]){
            x1.push_back(v[i]);
        }
        else if(v[i]<=x2[q-1]) {
            x2.push_back(v[i]);
        }
        
        if(v[i]>x1[p-1] && q>0 && v[i]>x2[q-1]) {
            if(x1[p-1]<x2[q-1]) {
                x1.push_back(v[i]);
            }
             else {
                x2.push_back(v[i]);
            }
        }
    }
    
    ll ans=0;
if (x1.size() > 1) {
    for(int i = 0; i < x1.size()-1; i++) {
        if(x1[i+1] > x1[i]) {
            ans++;
        }
    }
}
if (x2.size() > 1) {
    for(int i = 0; i < x2.size()-1; i++) {
        if(x2[i+1] > x2[i]) {
            ans++;
        }
    }
}
    cout<<ans<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}