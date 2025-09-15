#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static const int64 INF = (int64)4e18; // big enough for our counting needs

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<bool> blocked(10, false);
    for (int i = 0; i < N; ++i) {
        int d; cin >> d;
        blocked[d] = true;
    }

    vector<int64> queries(Q);
    for (int i = 0; i < Q; ++i) cin >> queries[i];

    vector<int> allowed;
    for (int d = 0; d < 10; ++d) if (!blocked[d]) allowed.push_back(d);
    int M = (int)allowed.size();
    bool zeroAllowed = !blocked[0];
    int firstDigitChoices = M - (zeroAllowed ? 1 : 0);

    if (M == 0) return 0;

    if (M == 1) {
        int only = allowed[0];
        for (auto k : queries) {
            if (zeroAllowed && only == 0) {
                cout << 0 << '\n';
                continue;
            }
            if (k > 18) {
                string s((size_t)k, char('0' + only));
                cout << s << '\n';
            } else {
                int64 v = 0;
                for (int64 i = 0; i < k; ++i) v = v * 10 + only;
                cout << v << '\n';
            }
        }
        return 0;
    }

    vector<int64> power;
    power.push_back(1);
    while (power.size() < 60) {
        long long tmp = (long long)power.back() * M;
        if (tmp > INF) power.push_back(INF);
        else power.push_back((int64)tmp);
        if (power.back() == INF) break;
    }

    auto countLength = [&](int len) -> int64 {
        if (len <= 0) return 0;
        long long tmp = (long long)firstDigitChoices * power[len - 1];
        return (tmp > INF) ? INF : (int64)tmp;
    };

    for (auto original : queries) {
        int64 k = original;
        if (zeroAllowed) {
            if (k == 1) {
                cout << 0 << '\n';
                continue;
            }
            --k;
        }

        int length = 1;
        int64 rank = k;
        while (true) {
            int64 c = countLength(length);
            if (rank <= c) break;
            rank -= c;
            ++length;
        }

        string digits;
        digits.reserve(length);
        for (int pos = 0; pos < length; ++pos) {
            int remain = length - pos - 1;
            for (int d : allowed) {
                if (pos == 0 && d == 0) continue;
                int64 block = power[remain];
                if (rank > block) {
                    rank -= block;
                } else {
                    digits.push_back(char('0' + d));
                    break;
                }
            }
        }

        int64 value = 0;
        for (char c : digits) value = value * 10 + (c - '0');
        cout << value << '\n';
    }

    return 0;
}