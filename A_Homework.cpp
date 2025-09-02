#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string a, b, c;
        cin >> n;
        cin>> a;
        cin>> m;
        cin >> b >> c;

        string begin = "", end = "";

        for (int i = 0; i < m; i++) {
            if (c[i] == 'V') {
                begin = b[i] + begin;
            } else {
                end = end + b[i];
            }
        }
        cout << begin + a + end << endl;
    }
    return 0;
}
