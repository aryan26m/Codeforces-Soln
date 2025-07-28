#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int,int>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define fast ios::sync_with_stdio(false); cin.tie(0);
const int INF = 1e18;

// Input array
vi inputArray(int n) {
    vi a(n);
    for (int &x : a) cin >> x;
    return a;
}

// Debug print
void printArray(const vi &a) {
    for (int x : a) cout << x << ' ';
    cout << '\n';
}

// GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Prime check
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Binary Search
bool binarySearch(const vi &a, int target) {
    int low = 0, high = a.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == target) return true;
        if (a[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// nCr using Fermat's Little Theorem
int power(int x, int y, int p) {
    int res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1) res = res * x % p;
        y >>= 1;
        x = x * x % p;
    }
    return res;
}

int modInverse(int n, int p) {
    return power(n, p - 2, p);
}

// int nCr(int n, int r, int p = MOD) {
//     if (r > n || r < 0) return 0;
//     static vector<int> fact(1, 1);
//     while ((int)fact.size() <= n)
//         fact.push_back(fact.back() * fact.size() % p);
//     return fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p;
// }

// Comparator (Descending Order)
bool comp(int a, int b) {
    return a > b;
}

// Frequency Map Update
void push(map<int, int> &mp, int k, int v) {
    mp[k] += v;
}

const int
	MAXN = 105,
	MOD = 100000000;

int32_t main() {
    fast;

int n1, n2, k1, k2;
int dp[MAXN][MAXN][2];
	cin >> n1 >> n2 >> k1 >> k2;
	
    dp[0][0][0] = dp[0][0][1] = 1;

    // Initialize base cases for dp[i][0][0] and dp[0][j][1]
    for (int i = 1; i <= n1; ++i) {
        if (i <= k1)
            dp[i][0][0] = 1;
    }
    for (int j = 1; j <= n2; ++j) {
        if (j <= k2)
            dp[0][j][1] = 1;
    }

    for (int i = 0; i <= n1; ++i)
    for (int j = 0; j <= n2; ++j)
    {
        if (i || j) {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
        for (int k = 1; k <= k1 && i - k >= 0; ++k)
            dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
            
        for (int k = 1; k <= k2 && j - k >= 0; ++k)
            dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
    }
    
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << endl;

	return 0;
}