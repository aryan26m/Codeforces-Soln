#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll L, W, R, G, B;
        cin >> L >> W >> R >> G >> B;

        vector<ll> sides = {L, L, W, W};
        vector<ll> color = {R, G, B};

        bool ok4 = false;

        // ---------- Check cost = 4 ----------
        for (int mask = 0; mask < 81 && !ok4; mask++) {
            vector<ll> used(3, 0);
            int x = mask;
            for (int i = 0; i < 4; i++) {
                int c = x % 3;
                x /= 3;
                used[c] += sides[i];
            }
            if (used[0] == R && used[1] == G && used[2] == B)
                ok4 = true;
        }

        if (ok4) {
            cout << 4 << '\n';
            continue;
        }

        bool ok5 = false;

        // ---------- Check cost = 5 ----------
        for (int splitSide = 0; splitSide < 4 && !ok5; splitSide++) {
            ll S = sides[splitSide];

            for (int c1 = 0; c1 < 3 && !ok5; c1++) {
                for (int c2 = c1 + 1; c2 < 3 && !ok5; c2++) {
                    int c3 = 3 - c1 - c2;

                    vector<int> otherSides;
                    for (int i = 0; i < 4; i++)
                        if (i != splitSide)
                            otherSides.push_back(i);

                    for (int mask = 0; mask < 27 && !ok5; mask++) {
                        vector<ll> used = {0, 0, 0};
                        int x = mask;

                        for (int i = 0; i < 3; i++) {
                            int c = x % 3;
                            x /= 3;
                            used[c] += sides[otherSides[i]];
                        }

                        ll low = max(0LL, S - (color[c2] - used[c2]));
                        ll high = min(S, color[c1] - used[c1]);

                        if (low <= high && color[c3] >= used[c3]) {
                            ok5 = true;
                        }
                    }
                }
            }
        }

        if (ok5) cout << 5 << '\n';
        else cout << 6 << '\n';
    }

    return 0;
}
