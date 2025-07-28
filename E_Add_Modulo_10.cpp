#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
   ll n;
   cin>>n;
   vector <ll> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   bool check=true;
   bool zero=false;
   for(int i=1;i<n;i++){
    if(v[i]!=v[i-1]){
        check = false;
    }
    if(v[i]%10==0||v[i-1]%10==0 ||v[i]%10==5 ||v[i-1]%10==5 ){
        zero=true;
    }
   }

   sort(v.begin(),v.end());
   if(check){
    cout<<"YES"<<endl;
    return;
   }
   else if(zero){
    for(int i=0;i<n;i++){
        if(v[i]%10==5){
            v[i]=v[i]+5;
        }
    }
    bool va=true;
       for(int i=1;i<n;i++){
    if(v[i]!=v[i-1]){
        va = false;
    }
   }
   if
   if(va){
cout<<"YES"<<endl;
return;   
}
   }
   else{
      for(int i=0;i<n;i++){
        if(v[i]%10!=2){
            while(v[i]%10!=2){
                v[i]=v[i]+(v[i]%10);
            }
        }
      }
    //   sort(v.begin(),v.end());
      bool x=true;
      for(int i=1;i<n;i++){
        //   cout<<v[i]<<" "<<v[i-1]<<endl;
        if((v[i]-v[i-1])%20 != 0){
            x=false;
            break;
        }
      }
      if(x){
        cout<<"YES"<<endl;
        return;
    }
}
cout<<"NO"<<endl;
//    cout
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}