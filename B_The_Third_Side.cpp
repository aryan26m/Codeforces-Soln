#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    if(n==1){
        cout<<v[0]<<endl;
    }
    else{
        long ans=0;
         long sum=v[0]+v[1];
         ans=sum-1;
         for(int i=2;i<n;i++){
            ans+=v[i]-1;
         }
    cout<<ans<<endl;
        }
}

int main(){
    int t;
    cin>>t;

    while(t-- ){
        solve();
    }
}