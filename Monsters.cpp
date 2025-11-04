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

// Comparator (Descending Order)
bool comp(int a, int b) {
    return a > b;
}

// Frequency Map Update
void push(map<int, int> &mp, int k, int v) {
    mp[k] += v;
}
#define F first
#define S second
using state=pair<int,int>;

int n,m;
vector<state> mons;
state st;
vector<state> bond;
vector<vector<char>> g;
vector<vector<int>> dismons;
vector<vector<int>> disper;
vector<vector<pii>> parent;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dirc[] = {'D', 'U', 'R', 'L'};

bool is_valid(int x, int y) {
    if(x>=0 && x<n && y>=0 && y<m && g[x][y]=='.') {
        return true;
    }
    return false;
}

void monsdfs(){
    queue<state> q;
    for(auto x : mons){
        q.push(x);
        dismons[x.F][x.S]=0;
    }
    while (q.size())
    {
         auto p=q.front();
         q.pop();
         int x=p.F;
         int y=p.S;
         for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
          if(is_valid(nx,ny)) {
            if(dismons[nx][ny] > dismons[x][y]+1){
                dismons[nx][ny]=dismons[x][y]+1;
                q.push({nx,ny});
            }
          }
        }
    }
}

void perdfs(state st){
    queue<state> q;
    q.push(st);
    disper[st.F][st.S]=0;
    parent[st.F][st.S] = {-1, -1};
    while (q.size())
    {
         auto p=q.front();
         q.pop();
         int x=p.F;
         int y=p.S;

         for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
          if(is_valid(nx,ny)) {
            if(disper[nx][ny] > disper[x][y]+1){
                disper[nx][ny]=disper[x][y]+1;
                parent[nx][ny] = {x, y};
                q.push({nx,ny});
            }
          }
        }
    }
}

// Reconstruct path from (ex,ey) to st
string get_path(state st, state en) {
    string path;
    state cur = en;
    while (cur != st) {
        pii par = parent[cur.F][cur.S];
        int px = par.F, py = par.S;
        if (px == -1 && py == -1) break;
        for (int d = 0; d < 4; ++d) {
            if (px + dx[d] == cur.F && py + dy[d] == cur.S) {
                path += dirc[d];
                break;
            }
        }
        cur = par;
    }
    reverse(path.begin(), path.end());
    return path;
}

// Solve Function
void solve() {
    cin>>n>>m;
    g.resize(n);
    dismons.resize(n,vector<int>(m,INF));
    disper.resize(n,vector<int>(m,INF));
    parent.resize(n, vector<pii>(m, {-1, -1}));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            g[i].pb(ch);
            if(ch=='M'){
                mons.pb({i,j});
            }
           else if(ch=='A'){
                st={i,j};
                 if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                bond.push_back({i, j});
            }
            }
            else if((i == 0 || j == 0 || i == n-1 || j == m-1) && ch=='.') {
              bond.push_back({i, j});
            }
        }
    }
    monsdfs();
    perdfs(st);
    for(auto x  : bond){
        if(disper[x.F][x.S]<dismons[x.F][x.S]){
            cout<<"YES"<<endl;
            cout<<disper[x.F][x.S]<<endl;
            cout<<get_path(st, x)<<endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    fast;
    solve();
    return 0;
}
