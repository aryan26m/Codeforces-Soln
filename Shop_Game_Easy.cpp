#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> ar(n);
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        string s;
        cin >> s;

        long long zero = 0;
        long long one = 0;
        long long mx = ar[0];
        for (int i = 0; i < k; i++) {
             if(s[i]=='0'){
               auto it = 
             }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}