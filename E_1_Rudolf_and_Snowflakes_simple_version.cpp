#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll lim=1e6+5;

vector<bool> check(lim, false);
void values() {
  ll i=2;
  ll j=3;
  ll mul=(i*j)+1;
  while(mul<lim){
      check[mul]=true;
      ll total=mul;
      ll p=i;
      while(total<lim && total>0){
        // cout<<total<<endl;
        total=(total*p)+1;
        if(total<lim){
            check[total]=true;
        }
      }
      i++;
      j++;
      mul=(i*j)+1;
  }
}

int solve() {
    ll n;
    cin>>n;
    if(check[n]==true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    values();// Call once before test cases

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
