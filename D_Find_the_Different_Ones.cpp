#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
ll solve() {
    int n;
    cin>>n;
    vector <ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector <ll> dif(n);
    dif[n-1]=n;
    for(int i=n-2;i>=0;i--){
        if(v[i]==v[i+1]){
            dif[i]=dif[i+1];
        }
        else{
            dif[i]=i+1;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << dif[i] << endl;
    // }
    ll q;
    cin>>q;
    while(q--){
        ll l;
        ll r;
        cin>>l>>r;
        l--;
        r--;

        if(dif[l]<=r){
            cout << l+1 <<" "<<dif[l]+1<<endl;
        }
        else{
            cout<<-1<<" "<<-1<<endl;
        }
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
      solve();
      cout<<endl;
    }
    return 0;
}
