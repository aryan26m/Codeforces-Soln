#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
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
#define fst ios::sync_with_stdio(false); cin.tie(0);
const int MOD = 1e9 + 7;
const int INF = 1e18;

// Input array
vi enterv(int n) {
    vi arr(n);
    for (int &x : arr) cin >> x;
    return arr;
}
// Input 2D array
vvi enterv2D(int n, int m) {
    vvi arr(n, vi(m));
    for (int i = 0; i < n; ++i)
        for (int &x : arr[i]) cin >> x;
    return arr;
}

// Debug print
void printArry(const vi &arr) {
    for (int x : arr) cout << x << ' ';
    cout << '\n';
}
void print2DArry(const vvi &matrix) {
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << '\n';
    }
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
bool binrySerch(const vi &arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// nCr using Fermt's Little Theorem
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
    static vector<int> fct(1, 1);
    while ((int)fct.size() <= n)
        fct.push_back(fct.back() * fct.size() % p);
    return fct[n] * modInverse(fct[r], p) % p * modInverse(fct[n - r], p) % p;
}

// Comparator (Descending Order)
bool comp(int a, int b) {
    return a > b;
}

// Frequency Map Update
void push(map<int, int> &mp, int k, int v) {
    mp[k] += v;
}

// Union-Find (Disjoint Set Union)
struct UnionFind {
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int _n) {
        n = set_size = _n;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i, rank[i] = 1;
    }
    int find(int x) {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }
    void merge(int x, int y) {
        int xcur = find(x), ycur = find(y);
        if (xcur == ycur) return;
        if (rank[xcur] >= rank[ycur]) {
            parent[ycur] = xcur;
            rank[xcur] += rank[ycur];
        } else {
            parent[xcur] = ycur;
            rank[ycur] += rank[xcur];
        }
        set_size--;
    }
    void reset() {
        set_size = n;
        for (int i = 1; i <= n; i++) parent[i] = i, rank[i] = 1;
    }
    int size() { return set_size; }
    void print() { for (int i = 1; i <= n; i++) cout << i << "->" << parent[i] << endl; }
};
vector<vector<int>> g;
vector<int> subtree;
void dfs(int node,int par){
    subtree[node]=1;
    for(int x:g[node]){
        if(x!=par){
            dfs(x,node);
            subtree[node]+=subtree[x];
        }
    }
}
void solve() {
    int n;
    cin>>n;
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    subtree.assign(n+1,0);
    dfs(1,0);
    debug(subtree);
    int ans=subtree[1]/2;
    cout<<ans;
}

int32_t main() {
    fst;
   solve();
    return 0;
}
