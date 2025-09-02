#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    int ans = INT_MAX;
    int idx = 0;
    for(int i=0; i<n; i++){
        if(v[i] <= ans){
        idx = i;
        ans = v[i];}
    }
    
    int ans1 = INT_MAX;
    for(int i=0; i<n; i++){
        if(idx!=i && ans1>=v[i])
        ans1 = v[i];
    }
    
    ans = ans+ans1;
    
    for(int i=0; i<n-1; i++){
        ans = min(ans, (v[i] + (v[i+1])/2));
    }
    
    cout<<ans<<endl;
}
}