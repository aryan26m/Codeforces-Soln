#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n; 
    cin>>n;
    vector<ll>v(n);
    vector<ll>ans;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll max1=0;
    ll max2=0;ll sum=0;
    for(int i=0;i<n;i++){
        sum += v[i];
        if(v[i] > max1){
            max1 = v[i];
        }
    }
    int cnt=0;
    // Find the second maximum (max2) which is not equal to max1
    for(int i=0;i<n;i++){
        if(v[i] != max1){
            max2 = max(max2, v[i]);
        }
        else{
            cnt++;
        }
    }
          if(n==2){
              cout<<0<<endl;
          }
          else{
          for(int i=0;i<n;i++){
               ll rem=sum-v[i];
               if(v[i]==max1 ){
                   ll x=rem-max2;
                   if(x==max2){
                    ans.push_back(i+1);
                   }
                   if(cnt>1){
                       
                       ll q=rem-max1;
                       if(q==max1){
                           ans.push_back(i+1);
                        }
                   }
               }
               else{
                ll x=rem-max1;
                if(x==max1){
                    ans.push_back(i+1);
                }
               }
          }
          if(max2==0 && n==3){
            cout<<3<<endl;
            for(int i=0;i<3;i++){
                cout<<i+1<<" ";
            }
          }
          else{
              cout<<ans.size()<<endl;
              for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
              }
          }
        }

}

