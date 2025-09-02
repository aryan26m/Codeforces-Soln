#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

bool canSplit(const string &s, int K, int target) {
    int n = (int) s.size();
    vector<int> pre0(n + 1, 0), pre1(n + 1, 0), arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre0[i] = pre0[i - 1] + (s[i - 1] == '0');
        pre1[i] = pre1[i - 1] + (s[i - 1] == '1');
        arr[i] = pre0[i] - pre1[i];
    }

    int size = 1;
    while (size < n + 1) size <<= 1;
    vector<int> segtree(2 * size, INT_MIN);

    for (int i = 1; i <= n; ++i)
        segtree[size + i - 1] = arr[i];
    for (int i = size - 1; i >= 1; --i)
        segtree[i] = max(segtree[2 * i], segtree[2 * i + 1]);

    auto query = [&](int l, int r) -> int {
        int res = INT_MIN;
        l += size - 1;
        r += size - 1;
        while (l <= r) {
            if ((l & 1) == 1) res = max(res, segtree[l++]);
            if ((r & 1) == 0) res = max(res, segtree[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    };

    int parts = 0;
    int l = 0;

    while (l < n) {
        bool found = false;
        for (int r = l + 1; r <= n; ++r) {
            int base = pre1[r] - pre0[l];
            int max_arr = query(l + 1, r);
            int maxsubseq = max_arr + base;
            if (maxsubseq >= target) {
                parts++;
                l = r;
                found = true;
                break;
            }
        }
        if (!found) break;
        if (parts >= K) return true;
    }
    return parts >= K;
}

int maxMinScore(string s, int K) {
    int l = 1, r = (int) s.size(), ans = 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (canSplit(s, K, mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        string S; cin >> S;
        cout << maxMinScore(S, K) << "\n";
    }
}
