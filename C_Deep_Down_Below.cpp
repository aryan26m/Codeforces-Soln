#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector <pair<ll,int>> a;
    for(int i=0;i<n;i++){
        ll maxi=0;
        int k;
        cin>>k;
        vector<ll> v(k);
        for(int j=0;j<k;j++){
              ll x;
              cin>>x;
              v[j]=x-j+1;
             maxi=max(maxi,v[j]);
            }
            a.push_back({maxi,k});
        }
        sort(a.begin(),a.end());
        ll l=a[0].first;
        int p=a.size();
        ll ans=0;
        ll h=a[p-1].first;
        
        while(l<=h){
            ll m=(l+h)/2;
            // cout<<m<<endl;
            bool check = true;
            ll cur=m;
            for(int i=0;i<p;i++){
                // cout<<a[p].<<endl;
                if(cur>=a[i].first){
                    cur+=a[i].second;
                }
                else{
                check=false;
                break;
              }
        }
        if(check){
            ans=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<ans<<endl;

}
int main(){
   int t;
   cin>>t;
   while(t--){
    solve();
   }
}