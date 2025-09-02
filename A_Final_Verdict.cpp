#include <bits/stdc++.h>
using namespace std;

int main() {
   
   int t;
   cin>>t;
   while(t--){

    int n, x;
    cin >> n >> x;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        sum += v;
    }
    if (sum == 1LL * n * x) cout << "YES\n";
    else cout << "NO\n";
}
}