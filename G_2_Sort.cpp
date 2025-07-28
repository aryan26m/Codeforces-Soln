#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll bs(vector<ll>&a,ll h,ll n){
    ll l=1;
    ll ans=h;
    while (l<=h){
        ll m=(l+h)/2;
        ll task=0;
        for(int i=1;i<=n;i++){
            if(a[i]>m){
                task+=a[i]-m;
            }
        }
        for(int i=1;i<=n;i++){
            if (a[i]<m)
            {
                ll x=m-a[i];
                ll rem=x/2;
                task-=rem;
            }
        }
        if(task<=0){
           ans=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
    
}
void solve() {
    
    ll n,k;
    
    cin >> n >> k;
    
    vector<ll> v(n);
    
    for(ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll i=0;
    ll j=1;
    ll ans=0;
    while (j<n)
    {  
        if((v[j]*2)>v[j-1]){
            if(j-i == k){
                ans++;
                i++;
            }
            j++;
            // cout<<j<<endl;
        }
        else{
            i=j;
            j++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}
