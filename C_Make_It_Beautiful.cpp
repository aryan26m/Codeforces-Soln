#include <bits/stdc++.h>
using namespace std;
#define ll long long
void countBits(ll num, ll &total, vector<ll> &bits) {
    ll count0 = 0, count1 = 0;
    ll totalBits = sizeof(ll) * 8; // Total bits in an integer

    for (ll i = 0; i < totalBits; i++) {
        if (num & (1LL << i)) {
            count1++;
        } else {
            count0++;
            ll poww = (1LL << i);
           if(poww>0){
               bits.push_back(poww);
           }
        }
    }
    // cout<<count1<<"  "<<num<<endl;
    total+=count1;
}

int solve() {
    int n;
    ll k;
    cin>>n;
  cin>>k;
   vector <ll> v;
   for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    v.push_back(x);
   }
   ll total=0;
   vector <ll> bits;
   for(int i=0;i<n;i++){
    countBits(v[i],total,bits);
   }

   sort(bits.begin(),bits.end());
   for(ll i=0;i<bits.size();i++){
       
       if(k>=bits[i]){
       total++;
            k=k-bits[i];
            // cout<<k<<endl;
          }
          else{
            break;
          }
        }
   cout<<total<<endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) { solve(); }
}


