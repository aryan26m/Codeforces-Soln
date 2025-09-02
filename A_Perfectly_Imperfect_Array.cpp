#include <bits/stdc++.h>
using namespace std;

int  main() {
    int ans = 0;
    int l = 1;
    int h = 1000000;
    while (l <= h) {
        int m = (l + h) / 2;
        cout << m << endl << flush;  // send query
        string s;
        cin >> s;                    // judge responds

        if (s == "<") {              // secret number < m
            h = m - 1;
        } else {                     // secret number >= m
            ans = m;
            l = m + 1;
        }
    }
    cout << "! " << ans << endl << flush;  // final answer
}
