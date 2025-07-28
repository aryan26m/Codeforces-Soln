#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(){
    ll n;
    cin>>n;
    vector <ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        }
        ll count=1;
        cout<<1<<" ";
        for(ll i=1;i<n;i++)
{
          if(v[i-count]>=count+1){
            count++;
          }
          cout<<count<<" ";
}
cout<<endl;
}
 int main(){
    ll t;
    cin>>t;
    while(t--){solve();}
 }