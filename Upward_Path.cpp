#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A1(N), A2(N);
        for (int i = 0; i < N; i++) cin >> A1[i];
        for (int i = 0; i < N; i++) cin >> A2[i];

        // Build top row as min, bottom row as max
        vector<int> top(N), bottom(N);
        for (int i = 0; i < N; i++) {
            top[i] = min(A1[i], A2[i]);
            bottom[i] = max(A1[i], A2[i]);
        }

        // Check if both sequences are non-decreasing
        bool ok = true;
        for (int i = 1; i < N; i++) {
            if (top[i] < top[i-1] || bottom[i] < bottom[i-1]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}