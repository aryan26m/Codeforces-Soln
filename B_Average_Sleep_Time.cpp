#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k; 
    cin>>n>>k;
    vector<ll>v(n);
    vector<ll>pre(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=v[i]+pre[i-1];
    }

    
    ll ans=pre[k-1];
    for(int i=k;i<n;i++){
        ans+=pre[i]-pre[i-k];
    }



    double x=0;
    if(n==1 || k==1){
       x = n*1.0;
    }
    else{
        x=(n-1)*1.0;
    }
    double anss=ans/x;
    #include <iomanip>
    cout << fixed << setprecision(6) << anss << endl;
}
