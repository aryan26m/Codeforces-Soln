#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
   int n;
   cin >> n;
   vector <int> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];   
   }
    map <int , int> freq;
    map <int,int> idx;
    
    for(int i=0;i<n;i++){
        freq[v[i]]++;
         idx[v[i]]=i+1;
    }
    int mini=INT_MAX;
    for(auto x : freq){
        if(x.second==1){
            mini=min(mini,x.first);
        }
    }
    if(mini!=INT_MAX){
        cout << idx[mini]<<endl;
    }
    else{
        
        cout <<-1<<endl;
    }
        
}
int main(){
   int t;
   cin>>t;
   while(t--){
    solve();
   }
}