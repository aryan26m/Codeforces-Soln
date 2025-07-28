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
    while (v.size() > 1 && v[0] == v[1]) {
        v.erase(v.begin());
        n--;
    }
    while (v.size() > 1 && v[v.size() - 1] == v[v.size() - 2]) {
        v.pop_back();
        n--;
    }
    // cout<<v.size()<<endl;

    bool allequal=true;
    bool alnotequal=true;
    map <int,unordered_set<int>> vec;
    for(int i=1;i<n;i++){
        if(v[i]!=v[i-1]){
            vec[v[i]].insert(i);
            allequal=false;
        }
    }
    vec[v[0]].insert(0);
    n=v.size();
    if(allequal){
        cout<<0<<endl;
    }
    else{
        int ans=INT_MAX;
        for(auto x : vec){
            x.second.insert(0);
            x.second.insert(n-1);
            int size=x.second.size();
            // cout<<x.first<<"  "<<size<<endl;
                ans=min(ans,size);
        }
        cout<<ans-1<<endl;
        }
    }
    int main(){
        int t;
        cin>>t;
        while(t--){
            solve();
        }
    }