#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s;
    cin>>s;
    int x=(s[0]-'0')-1;
    int pre=x*10;
    int n=s.size();
    while(n>0){
        pre+=n;
        n--;
    }
     cout<<pre<<endl;
}


int main() {
    int t;
    cin>>t;
    while(t--){

        solve();
    }
    return 0;
}

