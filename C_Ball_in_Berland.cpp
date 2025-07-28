#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int a,b,k;
    cin >> a >> b >> k;
    vector<int> x(a+1,0), y(b+1,0);
    vector <int> boy;
    vector <int> girl;
    for(int i=0;i<k;i++){
        int q;
        cin >> q;
        boy.push_back(q);
        x[q]++;
    }
    for(int i=0;i<k;i++){
        int q;
        cin >> q;
        girl.push_back(q);
        y[q]++;
    }
    ll ans=0;
    for(int i=0;i<k;i++){
        int b=boy[i];
        int g=girl[i];
        ll rem=k-x[b]-y[g]+1;
        ans+=rem;
    }
    cout << ans / 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}