#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
   ll n,k;
   cin>>n>>k;
  ll ans=n;
  ll m=1;
  while(n%10==0){
    n=n/10;
  }
  while(n%5==0){
    n=n/5;
    if(m*2<=k){
        m=m*2;
    }
    else{
        break;
    }
  }
  while(n%2==0){
    n=n/2;
    if(m*5<=k){
        m=m*5;
    }
    else{
        break;
    }
  }
  while(m*10<=k){
      m=m*10;
  }
  m=(k/m)*m;
  ans=ans*m;
  cout<<ans<<endl;;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    // cout<<10050*14000<<endl;;
}