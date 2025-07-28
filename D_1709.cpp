#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector <int>a;
    vector <int>b;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }

    vector <pair<int,int>> ans;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
              if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                ans.push_back({1,(j+1)});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(b[j]>b[j+1]){
                // cout<<i<<" "<<j<<" ";
                  swap(b[j],b[j+1]);
                ans.push_back({2,(j+1)});
              }
        }
    }
    for(int i=0;i<n;i++){
              if(a[i]>b[i]){
                swap(a[i],b[i]);
                ans.push_back({3,(i+1)});
              }
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
}
int main(){
    int t;
    cin>>t;

    while(t-- ){
        solve();
    }
}