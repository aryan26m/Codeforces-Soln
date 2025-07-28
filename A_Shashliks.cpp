#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
   ll k,a,b,x,y;
   cin>>k>>a>>b>>x>>y;
   ll ans=0;
   if(a>k && b>k){
  cout <<0<<endl;
  return;
   } 
   ll two=0;
   ll one=0;
   if(x<y){
    if(k>=a){
        ll req=k-a;
        one=(req/x)+1;
        ll rem=k-(one*x);
        //  cout<<rem<<endl;
        if(rem>=b){
            two=(rem-b)/y;
            two++; 
        }
    }
    else{
        ll req=k-b;
        one=(req/y)+1;
    }
        ans=one+two;
    }
    else{
        if(k>=b){
            ll req=k-b;
            one=(req/y)+1;
            ll rem=k-(one*y);
        if(rem>=a){
            two=(rem-a)/x;
            two++; 
        }
    }
    else{
         ll req=k-a;
            one=(req/x)+1;
            
    }
        ans=one+two;
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