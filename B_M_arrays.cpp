#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> mp;
    int ans = 0;
    bool check[100001]; 
    memset(check, false, sizeof(check)); // Proper initialization

    for (int i = 0; i < n; i++) {
        int mod = a[i] % m;
        if (mod == 0) {
            ans = 1;
        } else {
            mp[mod]++;
        }
    }

    for (auto it : mp) {
        int x = it.first, freq1 = it.second;
        int y = m - x;

        if (!check[y]) {
            check[x] = true;
            check[y] = true;

            if (mp.find(y) != mp.end()) {
                int freq2 = mp[y];
                if (abs(freq1 - freq2) <= 1) {
                    ans++;
                } else {
                    ans += abs(freq1 - freq2) - 1 + 1;
                }
            } else {
                ans += freq1;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}