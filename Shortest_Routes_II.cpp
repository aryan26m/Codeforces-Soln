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
#define fast ios::sync_with_stdio(false); cin.tie(0);
const int MOD = 1e9 + 7;
const int INF = 1e18;

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
void printArray(const vi &a) {
    for (int x : a) cout << x << ' ';
    cout << '\n';
}
void print2DArray(const vvi &matrix) {
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

// Compara
bool comp(int a, int b) {
    return a > b;
}

// Frequency Map Update
void push(map<int, int> &mp, int k, int v) {
    mp[k] += v;
}

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> adj;
    adj.resize(n+1,vector<int> (n+1,1e18));
        for(int j=0;j<m;j++){
            int u,v,c;
            cin>>u>>v>>c;
            if(u==v){
                adj[u][v]=0;
            }
            adj[u][v]=min(adj[u][v],c);
            adj[v][u]=min(adj[v][u],c);
        }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    debug(adj);
    while (q--)
    {
int x,y;
cin>>x>>y;
if(x>y){
    int temp=x;
    x=y;
    y=temp;
}
if(x==y){
    cout<<0<<endl;
}
else if(adj[x][y]==1e18){
    cout<<-1<<endl;
}
else{
    cout<<adj[x][y]<<endl;
}
    }

}

int32_t main() {
    fast;
    solve();
    return 0;
}
