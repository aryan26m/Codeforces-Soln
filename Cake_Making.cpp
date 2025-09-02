#include <bits/stdc++.h>
using namespace std;

void solve() {
int n,m;
cin>>n>>m;
int mini=min(n,m);
int ans=n*m;
int x=ans-mini;
cout<<x<<endl;
}

int main(){
    int t = 1;
    solve();
    return 0;
}
