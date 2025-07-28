#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==b && b==c&&c==d){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;

    }
}

int main(){
    int t;
    cin>>t;

    while(t-- ){
        solve();
    }
}