#include <bits/stdc++.h>
using namespace std;

void solve() {
int n;
cin>>n;
vector <int> v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
int maxi=-1;
int idx=-1;
for(int i=0;i<n;i++){
    if(v[i]>maxi){
        maxi=v[i];
        idx=i;
    }
}
cout<<(idx+1)<<endl;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){

        solve();
    }
    return 0;
}
