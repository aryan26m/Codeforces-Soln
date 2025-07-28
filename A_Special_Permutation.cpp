#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
   int n;
   cin>>n;
   int temp=n;
          if(n%2==0){
              for(int i=0;i<n;i++){
                  cout<<temp<<" ";
                  temp--;              
                }
            }
            else{
                cout<<2<<" ";
                for(int i=1;i<n;i++){
                    if(temp==2){
                        temp--;
                    }
                       cout<<temp<<" ";
                       temp--;
                }
                cout<<endl;
            }
   cout<<endl;
}
int main(){
   int t;
   cin>>t;
   while(t--){
    solve();
   }
}