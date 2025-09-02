#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;

        int maxi = 0, cur = 0;
        for (char c : s) {
            if (c == '1') {
                cur++;
                maxi = max(maxi, cur);
            } else {
                cur = 0;
            }
        }
        if (maxi >= k) {
            cout << "NO"<<endl;
            continue;
        }
        cout << "YES"<<endl;
        vector<int> p(n);
        int small = 1, big = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
            {
                 p[i] = small++;
            }
            else{

                p[i] = big--;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << ' ';
            }
            cout << p[i];
        }
        cout << endl;
    }
    return 0;
}