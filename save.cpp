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
#define F first
#define S second
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

using state = pair<int,int>;
state st;
int n,m;
vector<vector<bool>> adj;
vector<state> bound;  
queue<state> mons;
queue<state> aocc;

vector<vector<int>> dis_pers;    // store min distances from person
vector<vector<char>> makedir;    // store min distances from person
vector<vector<int>> dis_mons;    // store min distances from monsters
vector<vector<state>> par;    // store parent
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char dir[] = {'D', 'R', 'U', 'L'};
void solve(){
     cin>>n>>m;
     adj.assign(n,vector<bool>(m));
     string s="";
    //  bound.assign(2*(n+m));
     dis_pers.assign(n, vector<int> (m, 1e9));
     dis_mons.assign(n, vector<int> (m, 1e9));
     par.assign(n, vector<state> (m, {-1,-1}));
     makedir.assign(n, vector<char> (m,'0'));
     rep(i,0,n){
        rep(j,0,m){
            char ch;
            cin>>ch;
            adj[i][j]=true;
            if(ch=='#'){
                adj[i][j]=false;
            }
            if(i==0 || j==0 || j==m-1 || i==n-1){
                bound.pb({i,j});
            }
            if(ch=='A'){
                dis_pers[i][j]=0;
                aocc.push({i,j});
                par[i][j]={-1,-1};
            }
            else if(ch=='M'){
                mons.push({i,j});
                dis_mons[i][j]=0;
            }
    }
}

while (mons.size()){
    auto it = mons.front();
    mons.pop();
    int x=it.F;
    int y=it.S;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
        if(adj[xx][yy] && dis_mons[xx][yy]==1e9){
            dis_mons[xx][yy]=dis_mons[x][y]+1;
          mons.push({xx,yy});
        }
    }
}

while (aocc.size()){
    auto it = aocc.front();
    aocc.pop();
    int x=it.F;
    int y=it.S;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
        if(adj[xx][yy] && dis_pers[xx][yy]==1e9){
            dis_pers[xx][yy]=dis_pers[x][y]+1;
          aocc.push({xx,yy});
          par[xx][yy]={x,y};
          makedir[xx][yy]=dir[i];
        }
    }
}

for(auto cell:bound) {
    if(dis_pers[cell.F][cell.S] < dis_mons[cell.F][cell.S]) {
       cout<<"YES"<<endl;
       cout << dis_pers[cell.F][cell.S] << endl;
       int x=cell.F;
       int y=cell.S;
       while (!(x==-1 && y==-1)  && makedir[x][y]!='0')
       {
        s.pb(makedir[x][y]);
        auto p = par[x][y];
        x=p.F;
        y=p.S;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl; 
        return;
    }
}



cout << "NO"<<endl;

}

int32_t main() {
    fast;
    int t = 1;
    solve();
    return 0;
}
