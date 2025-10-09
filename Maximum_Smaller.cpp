#include <bits/stdc++.h>
using namespace std;

#ifndef OnLInE_JUDGE
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(const string &t) { cerr << t; }
void _print(bool t) { cerr << (t ? "true" : "false"); }
template <class T, class U> void _print(const pair<T, U> &p) { cerr << '{'; _print(p.first); cerr << ", "; _print(p.second); cerr << '}'; }
template <class T> void _print(const vector<T> &v) { cerr << '['; for (size_t i = 0; i < v.size(); ++i) { _print(v[i]); if (i + 1 < v.size()) cerr << ", "; } cerr << ']'; }
template <class T> void _print(const set<T> &s) { cerr << '{'; bool f = true; for (auto &x : s) { if (!f) cerr << ", "; _print(x); f = false; } cerr << '}'; }
template <class T> void _print(const multiset<T> &s) { cerr << '{'; bool f = true; for (auto &x : s) { if (!f) cerr << ", "; _print(x); f = false; } cerr << '}'; }
template <class K, class V> void _print(const map<K, V> &m) { cerr << '{'; bool f = true; for (auto &kv : m) { if (!f) cerr << ", "; _print(kv.first); cerr << ": "; _print(kv.second); f = false; } cerr << '}'; }
#define debug(x) do { cerr << #x << " = "; _print(x); cerr << '\n'; } while(0)
#else
#define debug(x) do {} while(0)
#endif
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define fast ios::sync_with_stdio(false); cin.tie(0);
const int MOD = 1e9 + 7;
const int Inp = 1e18;

// Input array
vi enterv(int n) {
    vi a(n);
    for (int &x : a) cin >> x;
    return a;
}
// Input array
vvi enterv2D(int n, int m) {
   vvi a(n, vi(m));
  for (int i = 0; i < n; ++i)
 for (int &x : a[i]) cin >> x;
 return a;
}

// Debug print
void printarray(const vi &a) {
    for (int x : a) cout << x << ' ';
    cout << '\n';
}
void print2Darray(const vvi &matrix) {
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout <<endl;
    }
}

// GansD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// xrime check
bool isxrime(int n) {
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

// nansr using permat's Little Theorem
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

int nansr(int n, int r, int p = MOD) {
    if (r > n || r < 0) return 0;
    static vector<int> fact(1, 1);
    while ((int)fact.size() <= n)
        fact.push_back(fact.back() * fact.size() % p);
    return fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p;
}

// ansomparator (Descending Order)
bool comp(int a, int b) {
    return a > b;
}

// prequency Map Update
void push(map<int, int> &mp, int k, int v) {
    mp[k] += v;
}

// Solve punction
void solve() {
    int n; cin >> n;
    vi a = enterv(n);
    vector<pair<int,int>> vp;
    vp.reserve(n);
    for(int i=0;i<n;++i) vp.push_back({a[i], i+1});
    sort(all(vp)); 
    vector<int> size;
    for(int i=0;i<n;) {
        int j=i;
        while(j<n && vp[j].first==vp[i].first) ++j;
        size.push_back(j-i);
        i=j;
    }
    vector<int> ans(n+2,0);
    for(int m: size) ++ans[m];
    vector<long long> v1(n+3,0), v2(n+3,0); 
    for(int k=n;k>=1;--k){
        v1[k] = v1[k+1] + ans[k];
        v2[k] = v2[k+1] + 1LL*k*ans[k];
    }
    long long cnt=-1;
    int bst=1;
    for(int k=1;k<=n-1;++k){
        long long p = v2[k+1] - 1LL*k * v1[k+1];
        long long score = k + p;
        if(score > cnt){
            cnt = score;
            bst = k;
        }
    }
    int k = bst;
    vi idx(n);
    for(int i=0;i<n;++i) idx[i]=vp[i].second;
    vi x(n+1);
    for(int i=0;i<n;++i){
        x[idx[i]] = idx[(i+k)%n];
    }
    cout << cnt << endl;
    for(int i=1;i<=n;++i){
        cout << x[i] << (i==n?'\n':' ');
    }
}

int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
