#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll cnt=1;
    vector <ll> dif;
    for(ll i=0;i<n-1;i++){
        ll diff = v[i+1] - v[i];
        if(diff>x){
            dif.push_back(diff);
        }   
    }
    sort(dif.begin(),dif.end());
    for(ll i=0;i<dif.size();i++){
        
    if(dif[i] % x == 0 && (dif[i]/x)-1 <= k){
            
                    k-= (dif[i]/x)-1;
          
            }
            else if(dif[i]%x!=0 && (dif[i]/x) <= k){
                    k -= (dif[i]/x);
            }
            else{
                cnt++;
            }
        }
        cout<<cnt<<endl;
}