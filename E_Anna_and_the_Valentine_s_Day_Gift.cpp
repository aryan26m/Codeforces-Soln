#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countDigits(ll n) {
    return (n == 0) ? 1 : (ll)log10(n) + 1;
}

ll cntzero(ll n) {
    ll count = 0;
    while (n % 10 == 0 && n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

void solve() {
   
    ll n, m;
    cin >> n >> m;
    vector<ll> v;

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    
    for (ll x : v) {
        cnt += countDigits(x);
    }
    
    vector<ll> zero;
    for (ll x : v) {
            ll y =cntzero(x);
            zero.push_back(y);
            
    }
    sort(zero.rbegin(), zero.rend());
    if(zero.size()>0){
       for(int i=0;i<n;i+=2){
           cnt -= zero[i]; 
        }
      
        // cout<<cnt << endl;  
            }
    if (cnt >  m) {
        cout << "Sasha" << endl;
    } else {
        cout << "Anna" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}