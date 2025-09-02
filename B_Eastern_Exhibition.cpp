#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (n % 2 == 1) {
            cout << 1 << "\n";
        } else {
            ll x_choices = x[n/2] - x[n/2 - 1] + 1;
            ll y_choices = y[n/2] - y[n/2 - 1] + 1;
            cout << x_choices * y_choices << "\n";
        }
    }
    return 0;
}
