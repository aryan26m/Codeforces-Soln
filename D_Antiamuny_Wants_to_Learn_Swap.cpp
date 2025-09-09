#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, q;
        
        cin >> n >> q;
        
        vector<int> a(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        
        vector<int> v(n + 1, 0), pref(n + 1, 0);

        for (int i = 1; i + 2 <= n; ++i) {

            if (a[i] > a[i + 1] && a[i + 1] > a[i + 2]) {
                v[i] = 1;
            }
                pref[i] = pref[i - 1] + v[i];
        }

        for (int i = max(1, n - 1); i <= n; ++i) {
            pref[i] = pref[i - 1];
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            if ((r - l + 1) < 3) {
                cout<<"YES"<<endl;
                continue;
            }

            int left = l;
            int right = r - 2;
            
            int cnt = pref[right] - pref[left - 1];
            
            cout << (cnt == 0 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}