#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = n - 1;
    long long sum1 = 0, sum2 = 0;
    int maxLen = 0;

    while (i <= j) {
        if (sum1 == sum2) {
            maxLen = i + (n - j - 1); // total taken from both sides
        }

        if (sum1 <= sum2) {
            sum1 += a[i++];
        } else {
            sum2 += a[j--];
        }
    }

    // Final check if sums matched at the end
    if (sum1 == sum2) {
        maxLen = max(maxLen, i + (n - j - 1));
    }

    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
