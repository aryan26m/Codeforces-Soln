#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int P = 0, N = 0;
    for(char c : s) {
        if(c == '+') ++P;
        else ++N;
    }

    int q;
    cin >> q;

    while(q--) {
        long long a, b;
        cin >> a >> b;

        if(a == b) {
            if(P == N) cout << "YES\n";
            else cout << "NO\n";
        } else {
            long long d = a - b;
            long long T = -b * (P - N);
            if(d == 0) { 
                if(P == N) cout << "YES\n";
                else cout << "NO\n";
                continue;
            }
            if(T % d != 0) { 
                cout << "NO\n";
            } else {
                long long K = T / d;
                if(K >= -N && K <= P) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}
