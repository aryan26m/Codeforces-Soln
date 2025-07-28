#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    } 
    bool ans=false;
    for(int i=0;i<n-1;i++){
        if(abs(v[i]-v[i+1])<=1){
            ans=true;
            break;
        }
    }
    ll cnt=INT_MAX;
    if(ans){
        cout<<0<<endl;
        return;
    }
    else{
        for(ll i=0;i<n-2;i++){
            ll k=0;
            ll x1=min(v[i], v[i+1]);
            ll x2=max(v[i], v[i+1]);    
            for(ll j=i+2;j<n;j++){
                if(x1<=v[j]+1 && x2>=v[j]){
                    k++;
                    ans=true;
                    cnt=min(cnt,k);
                }
                else{
                    k++;
                }
            }
            }
        for(ll i=1;i<n-1;i++){
            ll k=0;
                      ll x1=min(v[i], v[i+1]);
            ll x2=max(v[i], v[i+1]); 
            for(ll j=i-1;j>=0;j--){
                if(x1<=v[j]+1 && x2>=v[j]){
                    k++;
                    ans=true;
                    cnt=min(cnt,k);
                }
                else{
                    k++;
                }
            }
            }
            }
        if(ans){
            cout<<cnt<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
int main(){
 int t;
 cin>>t;
 while(t--){
    solve();
 }
}
