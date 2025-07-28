#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, w;
    cin >> n >> w;
    multiset<long long> ms;
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        ms.insert(x);
    }

    int h = 1;
    long long left = w;
    while (!ms.empty()) {
        auto itr = ms.upper_bound(left);
        if (itr == ms.begin()) {
            left = w;
            h++;
        }
         else {
            itr--;
            left -= *itr;
            ms.erase(itr);
        }
    }
    cout << h << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}