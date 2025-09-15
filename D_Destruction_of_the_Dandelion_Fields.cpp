#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    if (!(cin >> cases)) return 0;
    while (cases--) {
        int count;
        cin >> count;

        vector<int> values(count);
        for (int i = 0; i < count; ++i) cin >> values[i];

        long long even_sum = 0;
        vector<int> odds;
        for (int v : values) {
            if ((v & 1) == 0) even_sum += v;
            else odds.push_back(v);
        }

        if (odds.empty()) {
            cout << 0 << '\n';
            continue;
        }

        sort(odds.begin(), odds.end(), greater<int>());

        int take = (static_cast<int>(odds.size()) + 1) / 2;
        long long odd_sum = accumulate(odds.begin(), odds.begin() + take, 0LL);

        long long result = even_sum + odd_sum;
        cout << result << '\n';
    }

    return 0;
}
