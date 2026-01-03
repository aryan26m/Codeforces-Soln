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

// Union-Find (Disjoint Set Union)
struct UnionFind {
    int n, set_size, *parent, *rank;
    UnionFind() {}
    UnionFind(int a) {
        n = set_size = a;
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

struct DSU {
    vector<int> p, sz;
    DSU(int n=0){ init(n); }
    void init(int n){
        p.resize(n); sz.assign(n,1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
    }
};

struct Seg { int x1,y1,x2,y2; };

void solve(){
    int w,h;
    cin>>w>>h;
    int n;
    cin>>n;
    vector<Seg> segs(n);
    rep(i,0,n){
        cin>>segs[i].x1>>segs[i].y1>>segs[i].x2>>segs[i].y2;
    }

    for(auto &s: segs){
        bool vert = (s.x1==s.x2);
        bool hor  = (s.y1==s.y2);
        if(!(vert||hor)){ cout<<"Invalid"; return ; }
        if(vert && s.y1==s.y2){ cout<<"Invalid"; return ; }
        if(hor && s.x1==s.x2){ cout<<"Invalid"; return ; }
        if(min(s.x1,s.x2)<0 || max(s.x1,s.x2)>w || min(s.y1,s.y2)<0 || max(s.y1,s.y2)>h){
            cout<<"Invalid"; return ;
        }
        if(s.x1>s.x2) swap(s.x1,s.x2);
        if(s.y1>s.y2) swap(s.y1,s.y2);
    }

    auto checker = [](int a,int b,int c,int d)->bool{
        if(a<=c && d<=b && (a<c || d<b)) return true;
        if(c<=a && b<=d && (c<a || b<d)) return true;
        return false;
    };

    unordered_map<int, vector<pair<int,int>>> vert, hor;
    vert.reserve(n*2);
    hor.reserve(n*2);

    for(auto &s: segs){
        if(s.x1==s.x2){
            int x=s.x1;
            int a=s.y1,b=s.y2;
            for(auto &pr: vert[x]){
                int l=pr.first, r=pr.second;
                if(checker(l,r,a,b)){
                    cout<<"Invalid";
                    return ;
                }
            }
            vert[x].push_back({a,b});
        } else {
            int y=s.y1;
            int a=s.x1,b=s.x2;
            for(auto &pr: hor[y]){
                int l=pr.first, r=pr.second;
                if(checker(l,r,a,b)){
                    cout<<"Invalid";
                    return ;
                }
            }
            hor[y].push_back({a,b});
        }
    }

    set<int> xs{0,w}, ys{0,h};
    for(auto &s: segs){
        xs.insert(s.x1); xs.insert(s.x2);
        ys.insert(s.y1); ys.insert(s.y2);
    }
    vector<pair<int,pair<int,int>>> vlist;
    vector<pair<int,pair<int,int>>> hlist;
    for(auto &s: segs){
        if(s.x1==s.x2) vlist.push_back({s.x1,{s.y1,s.y2}});
        else hlist.push_back({s.y1,{s.x1,s.x2}});
    }
    for(auto &V: vlist){
        int x=V.first, y1=V.second.first, y2=V.second.second;
        for(auto &H: hlist){
            int y=H.first, x1=H.second.first, x2=H.second.second;
            if(x1<=x && x<=x2 && y1<=y && y<=y2){
                xs.insert(x); ys.insert(y);
            }
        }
    }

    vector<int> vx(all(xs)), vy(all(ys));
    int X=vx.size(), Y=vy.size();
    if(X<2 || Y<2){ cout<<"Invalid"; return; }

    unordered_map<int,int> mx, my;
    mx.reserve(X*2); my.reserve(Y*2);
    rep(i,0,X) mx[vx[i]]=i;
    rep(j,0,Y) my[vy[j]]=j;

    vector<vector<bool>> vwall(X, vector<bool>(Y-1,false));
    vector<vector<bool>> hwall(Y, vector<bool>(X-1,false));

    rep(j,0,Y-1){ vwall[0][j]=true; vwall[X-1][j]=true; }
    rep(i,0,X-1){ hwall[0][i]=true; hwall[Y-1][i]=true; }

    for(auto &s: segs){
        if(s.x1==s.x2){
            int xi=mx[s.x1];
            int y1=my[s.y1], y2=my[s.y2];
            if(y1==y2){ cout<<"Invalid"; return; }
            rep(yj,y1,y2) vwall[xi][yj]=true;
        } else {
            int yi=my[s.y1];
            int x1=mx[s.x1], x2=mx[s.x2];
            if(x1==x2){ cout<<"Invalid"; return; }
            rep(xi,x1,x2) hwall[yi][xi]=true;
        }
    }

    int cells=(X-1)*(Y-1);
    DSU dsu(cells);
    auto id = [&](int xi,int yj){ return yj*(X-1)+xi; };

    rep(xi,0,X-2) rep(yj,0,Y-1){
        if(!vwall[xi+1][yj]) dsu.unite(id(xi,yj), id(xi+1,yj));
    }
    rep(xi,0,X-1) rep(yj,0,Y-2){
        if(!hwall[yj+1][xi]) dsu.unite(id(xi,yj), id(xi,yj+1));
    }

    unordered_map<int, vector<pair<int,int>>> comp;
    comp.reserve(cells*2);
    rep(xi,0,X-1) rep(yj,0,Y-1){
        comp[dsu.find(id(xi,yj))].push_back({xi,yj});
    }

    for(auto &kv: comp){
        auto &vec=kv.second;
        int minx=LLONG_MAX, maxx=-1, miny=LLONG_MAX, maxy=-1;
        for(auto &p: vec){
            minx=min(minx,p.first);
            maxx=max(maxx,p.first);
            miny=min(miny,p.second);
            maxy=max(maxy,p.second);
        }
        int area=(maxx-minx+1)*(maxy-miny+1);
        if(vec.size()!=area){
            cout<<"Invalid";
            return;
        }
    }

    vector<int> roots; roots.reserve(comp.size());
    for(auto &kv: comp) roots.push_back(kv.first);
    int P=roots.size();
    unordered_map<int,int> mpIdx; mpIdx.reserve(P*2);
    rep(i,0,P) mpIdx[roots[i]]=i;

    vector<int> color(P);
    rep(i,0,P){
        auto &cl=comp[roots[i]];
        int xi=cl[0].first, yj=cl[0].second;
        color[i]=(xi+yj)&1;
    }

    vector<vector<int>> adj(P);
    rep(xw,1,X-1) rep(yj,0,Y-1) if(vwall[xw][yj]){
        int a=mpIdx[dsu.find(id(xw-1,yj))];
        int b=mpIdx[dsu.find(id(xw,yj))];
        if(a!=b){
            if(color[a]==0 && color[b]==1) adj[a].push_back(b);
            else if(color[b]==0 && color[a]==1) adj[b].push_back(a);
        }
    }
    rep(yw,1,Y-1) rep(xi,0,X-1) if(hwall[yw][xi]){
        int a=mpIdx[dsu.find(id(xi,yw-1))];
        int b=mpIdx[dsu.find(id(xi,yw))];
        if(a!=b){
            if(color[a]==0 && color[b]==1) adj[a].push_back(b);
            else if(color[b]==0 && color[a]==1) adj[b].push_back(a);
        }
    }

    vector<int> l1, r1;
    rep(i,0,P) (color[i]==0? l1: r1).push_back(i);
    int R=r1.size();
    vector<int> rightIndex(P,-1);
    rep(i,0,R) rightIndex[r1[i]]=i;

    vector<int> right(R,-1), left(P,-1);
    function<bool(int, vector<char>&)> dfs2 = [&](int u, vector<char>& seen){
        for(int vComp: adj[u]){
            int v=rightIndex[vComp];
            if(v<0) continue;
            if(seen[v]) continue;
            seen[v]=true;
            if(right[v]==-1 || dfs2(right[v], seen)){
                right[v]=u;
                left[u]=v;
                return true;
            }
        }
        return false;
    };

    int ans=0;
    for(int u: l1){
        vector<char> seen(R,false);
        if(dfs2(u, seen)) ans++;
    }

    int mini = P - ans;
    cout<<mini;
}

signed main(){
 fast;
    solve();
 return 0;
}