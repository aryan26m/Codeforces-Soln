#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int,int>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define fast ios::sync_with_stdio(false); cin.tie(0);
const int MOD = 1e9 + 7;
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

int nCr(int n, int r, int p = MOD) {
    if (r > n || r < 0) return 0;
    static vector<int> fact(1, 1);
    while ((int)fact.size() <= n)
        fact.push_back(fact.back() * fact.size() % p);
    return fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p;
}

// Comparator (Descending Order)
bool comp(int a, int b) {
    return a > b;
}

// Frequency Map Update
void push(map<int, int> &mp, int k, int v) {
    mp[k] += v;
}



int minCost(int n, int k) {
    int m = v.size();

    priority_queue<pair<long long,int>> pq;

    vector<int> cnt(m, 0);
    int deal = 0;
    long long c1 = 0;
    for (int i = 0; n > 0; i++) {
        cnt[i] = n % 3;
        deal += cnt[i];
        c1 += cnt[i] * c[i];
        n /= 3;
    }

    if (deal > k) return -1;

    for (int i = 1; i < m; i++) {
        if (cnt[i]) {
            long long s2 = c[i] - 3 * c[i-1];
            for (int j = 0; j < cnt[i]; j++) {
                pq.push(make_pair(s2, i));
            }
        }
    }

    long long crnt = c1;

    while (!pq.empty() && deal < k) {
        auto top = pq.top(); pq.pop();
        long long s2 = top.first;
        int level = top.second;

        if (deal + 2 > k) break;

        deal += 2;   
        crnt -= s2;

        if (level > 1) {
            long long news = c[level-1] - 3 * c[level-2];
            for (int j = 0; j < 3; j++) {
                pq.push(make_pair(news, level-1));
            }
        }
    }

    return crnt;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << minCost(n, k) << "\n";
    }
    return 0;
}