#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector <int> ans;
    // ans.push_back(a[0]);
    // ans.push_back(a[n-1]);
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1  || (a[i]>a[i-1]&&a[i]>a[i+1]) || (a[i]<a[i-1]&& a[i]<a[i+1])){
            ans.push_back(a[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
