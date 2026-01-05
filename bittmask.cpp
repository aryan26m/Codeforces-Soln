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

// Solve Function
void solve() {
    // Write your logic her
    // int n;
    // cin>>n;
    // vi v=enterv(n);
    //  for(int i=0;i<(1<<n);i++){
    //     cout<<i<<": ";
    //      for(int j=0;j<n;j++){
    //          if((i>>j)&1){
    //             cout<<v[j]<<" ,";
    //          }
    //    }
    //      cout<<endl;
    //  }
    // int n=12;
    // //1100
    // bitset <4> b1(n);
    // cout<<b1.to_string()<<endl;
// bit magic 1
    // int q;
    // cin>>q;
    // int n=0;
    // while (q--)
    // {
    //      int t;
    //      cin>>t;
    //      if(t==1){
    //         int i;
    //         cin>>i;
    //         if((n>>i)&1){
    //             cout<<1<<endl;
    //         }
    //         else{
    //             cout<<0<<endl;
    //         }
    //      }
    //      else if(t==2){
    //         int i;
    //         cin>>i;
    //           n=(n|(1LL<<i));
    //      }
    //      else if(t==3){
    //         int i;
    //         cin>>i;
    //         n=(n&(~(1LL<<i)));
    //      }
    //      else if(t==4){
    //           int i;
    //           cin>>i;
    //           n=(n^(1LL<<i));
    //      }
    //      else{
    //         bool on=false;
    //         int sum=0;
    //         int count=0;
    //         for(int i=0;i<60;i++){
    //             if((n>>i)&1){
    //                 sum+=(1LL<<i);
    //                 count++;
    //                 on=true;
    //             }
    //         }
    //         if(t==5){
    //             if(count==60){
    //              cout<<1<<endl;   
    //             }
    //             else{
    //                 cout<<0<<endl;   
    //             }
    //         }
    //         else if(t==6){
    //              if(on){
    //              cout<<1<<endl;   
    //             }
    //             else{
    //                 cout<<0<<endl;   
    //             }
    //         }
    //         else if(t==7){
    //              if(on==false){
    //              cout<<1<<endl;   
    //             }
    //             else{
    //                 cout<<0<<endl;   
    //             }
    //         }
    //         else if(t==8){
    //              cout<<count<<endl;   
    //         }
    //         else{
    //             cout<<sum<<endl;
    //         }
    //      }
    // }


    //bit magic 2
    int n;
    cin>>n;
    bitset<64> b1(n);
    cout<<b1<<endl;
   int left=-1;
   int right=-1;
   int cnt=0;
   int bigpow=-1;
   int bigno=2;
   for(int i=63;i>=0;i--){
    if(b1[i]==1 && (n==(1LL<<i))){
        cnt=i;
    }
    if((bigpow==-1) && n!=0 && (n%(1LL<<i)==0)){
        bigpow=i;
    }
    if(b1[i]==1){
        if(right==-1) {right=i;}
        left=i;
    }
    if(i>0){
        if((1LL<<i)>=n){
            bigno=(1LL<<i);
        }
    }

   }

   cout<<right<<endl;
   cout<<left<<endl;
   if(cnt){
    cout<<1<<endl;
}
else{
       cout<<0<<endl;

   }
   if(bigpow==-1){
    cout<<-1<<endl;
   }
   else{

       cout<<(1LL<<bigpow)<<endl;
   }
    cout<<bigno<<endl;

    }
    

    int32_t main() {
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        solve();
        /* code */
    }
    
    return 0;
}
