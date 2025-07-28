#include <bits/stdc++.h>
using namespace std;

// Enable fast input-output operations
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, long long> mp;
    for (int i = 0; i < n; i++) {
        mp[(long long)a[i] - i]++;  // Store values safely using long long
    }

    long long ans = 0;
    for (auto it : mp) {
        long long count = it.second;
        if (count > 1) {
            ans += (count * (count - 1)) / 2;  // Efficient combination calculation
        }
    }

    cout << ans << "\n";
    return 0;
}

int main() {
    fastIO();  // Use fast I/O
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}