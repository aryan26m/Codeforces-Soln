#include<bits/stdc++.h>
using namespace std;
#define ll long long
void primeFactorization(ll n, map<ll, ll>& mp) {
    // Initialize the map to be empty (not needed if passed by reference and always empty)
    mp.clear();
// cout<<"@2222";
    // Handle factor 2 separately
    while (n % 2 == 0) {
        mp[2]++;
        n /= 2;
    }

    // Check odd factors up to sqrt(n)
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 1) mp[n]++;
        }
void solve(){
    ll n;
    cin >> n;
    map <ll,ll> mp;
    primeFactorization(n,mp);
    pair<ll, ll> max = {0ll, INT_MIN};
for (const auto& entry : mp) {
    if (entry.second > max.second) {
        max = entry;
    }
}
if(max.second>1){
    cout<<max.second<<endl;
    ll mul=1;
    for(ll i=0;i<max.second-1;i++){
        cout<<max.first<<" ";
        mul=mul*max.first;
    }
    ll  div=n/mul;
    cout<<div<<endl;
}
else{
    cout<<1<<endl;
    cout<<n<<endl;
}
}



    // for(auto x : mp){

    // }
    
int main() {
  int t;
  cin>> t;
  while(t--){
    solve();
  }
    return 0;
}