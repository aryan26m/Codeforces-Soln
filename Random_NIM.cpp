#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string p = "abcd"; 
        string ans;

        while ((int)ans.size() < n) {
            ans += p;
        }

        ans = ans.substr(0, n);

        cout << ans << "\n";
    }
}
