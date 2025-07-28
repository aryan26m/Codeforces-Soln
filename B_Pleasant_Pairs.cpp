#include <bits/stdc++.h>
using namespace std;
void solve()
{
int n;
cin >> n;
long long int v[n + 1];
for (int i = 1; i <= n; i++) {
    cin >> v[i];
}
long long int cnt=0;
for(long long int i=1;i<n;i++){
    long long int ch=v[i]-i;
    for(long long int j=ch;j<=n;j+=v[i]){
        if(j>0){
            long long int mul=v[j]*v[i];
            if(mul == (i + j) && i<j){
                cnt++;
            }
        }
    }
}
cout<<cnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}