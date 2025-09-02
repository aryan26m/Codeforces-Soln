#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000007LL;
const int N = 1001;
const int M = 10;

int n, m;
int dp[M][N][N];

int f(int i, int a, int b) {
    // Check invalid intervals or out-of-bound indices BEFORE accessing dp
    if (a < 1 || b < 1 || a > n || b > n || a > b) return 0;
    if (i == m) return 1;
    if (dp[i][a][b] != -1) return dp[i][a][b];

    int val1 = f(i + 1, a, b);
    int val2 = f(i, a + 1, b);
    int val3 = f(i, a, b - 1);
    int val4 = f(i + 1, a + 1, b - 1);

    int ans = ((val1 + val2 + val3 - val4)+MOD)%MOD;
    if (ans < 0) ans += MOD;

    return dp[i][a][b] = ans;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    cout << f(0, 1, n) << "\n";
    return 0;
}
