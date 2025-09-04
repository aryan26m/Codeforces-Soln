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
#define aint(x) (x).begin(), (x).end()
#define vi vector<int>
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

vector<int> segtree;
// void build(vector<int>&v,int start, int end ,int index){//build segement tree
//     if(start==end){
//         segtree[index]=v[start];
//         return;
//     }
//     int mid=(start+end)/2;
//     int left=index*2;
//     int right=(index*2)+1;
//     build(v,start,mid,left);
//     build(v,mid+1,end,right);
//     segtree[index]=min(segtree[left],segtree[right]);
// }
void build(vector<int> &v,int start,int end,int index){
    if(start==end){
        segtree[index]=v[start];
        return;
    }
    int mid=(start+end)/2;
    int left=2*index;
    int right=(2*index)+1;
    build(v,start,mid,left);
    build(v,mid+1,end,right);
    segtree[index]=min(segtree[left],segtree[right]);
}
void update(vector<int> &v,int start,int end,int index,int pos,int value){//update at a point in segment tree
// if(start==end){
//     v[pos]=value;
//     segtree[index]=v[pos];
//     return;
// }
// int mid=(start+end)/2;
// if(mid>=pos){
//     update(v,start,mid,2*index,pos,value);
// }
// else{
//     update(v,mid+1,end,(2*index)+1,pos,value);
// }
// segtree[index]=min(segtree[2*index],segtree[(2*index)+1]);
if(start==end){
    v[pos]=value;
    segtree[index]=v[pos];
    return;
}
int mid=(start+end)/2;
if(mid>=pos){
    update(v,start,mid,2*index,pos,val);
}
else{
    update(v,mid+1,end,(2*index)+1,pos,val);
}
segtree[index]=min(segtree[2*])
}
int query(int start,int end,int index,int l ,int r){//give sum from  l to r
    //compllete overlapp 
    //left .... start .... end  .... right;
    if(start>=l && end<=r){
        return segtree[index];
    }
    if(l>end || r<start){
        return INT_MAX;
    }
    int mid=(start+end)/2;
    int leftans=query(start,mid,2*index,l,r);
    int rightans=query(mid+1,end,(2*index)+1,l,r);
       return min(leftans,rightans);
}

void solve(){
    int n,m;
    cin>>n>>m;
    segtree.resize((4 * n - 1),-1);
    vi v=enterv(n);
    build(v,0,n-1,1);
    // debug(segtree);
    while (m--)
    {
     int x;
     cin>>x;
     if(x==1){
        int idx,val;
        cin>>idx>>val;
        update(v,0,n-1,1,idx,val);
    }
    else{
        int l,r;
        cin>>l>>r;
        cout<<query(0,n-1,1,l,r-1)<<endl;        
    }
    }
}

int32_t main() {
    fast;
   solve();
    return 0;
}
