#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX_POW = 18;
long long v[MAX_POW + 1];

void precompute() {
    v[0] = 1;
    for (int i = 1; i <= MAX_POW; i++) {
        v[i] = v[i - 1] * 10;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;

        for (int i = 1; i <= 18; i++) {
            if ((v[i] + 1) > n) {
                break;
            }
            if (n % (v[i] + 1) == 0) {
                int x = n / (v[i] + 1);
                ans.push_back(x);
            }
        }

        int size = ans.size();
        if (size == 0) {
            cout << 0 << "\n";
        } else {
            cout << size << "\n";
            sort(ans.begin(),ans.end());
            for (int i = 0; i < size; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
