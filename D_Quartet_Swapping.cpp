#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << 
// #define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int,int>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define fast ios::sync_with_stdio(false); cin.tie(0);
const int MOD = 1e9 + 7;
const int INF = 1e18;

struct Node {
  long long val;
  Node() : val(0) {}
  Node(long long v) : val(v) {}
  friend Node merge(Node l, Node r) { return Node(l.val + r.val); }
  void update(long long v) { val = v; }
};
 
struct SegmentTree {
  int n;
  vector<Node> seg;
  SegmentTree(int _n) : n(_n), seg(2 * _n) {}
  template <typename Type>
  SegmentTree(vector<Type> a) {
    n = int(a.size());
    seg.resize(2 * n);
    for (int i = 0; i < n; i++) seg[i + n] = Node(a[i]);
    for (int i = n - 1; i > 0; i--)
      seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
  }
  void update(int i, long long v) {
    for (seg[i += n].update(v); i >>= 1;)
      seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
  }
  Node query(int l, int r) {
    if (l > r) return Node();
    Node resl, resr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = merge(resl, seg[l++]);
      if (r & 1) resr = merge(seg[--r], resr);
    }
    return merge(resl, resr);
  }
};
 
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
int binarySearch(const vi &a, int target) {
    int low = 0, high = a.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == target) {
          return mid;
        }
        if (a[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
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
// Solve Function
void solve() {
    int n;
    cin >> n;
    vi v = enterv(n);

    if (n == 4) {
        if (v[0] > v[2]) {
            swap(v[0], v[2]);
            swap(v[1], v[3]);
        }
        printArray(v);
        return;
    }

    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) even.push_back(v[i]);
        else odd.push_back(v[i]);
    }
      auto findParity = [&](vector<int> &v) {
      int m = v.size();
      SegmentTree sg(n + 1);
      int res = 0;
      for (int i = 0; i < m; i++) {
        sg.update(v[i], 1);
        res += sg.query(v[i] + 1, n).val;
      }
      return res & 1;
    };
 
    int oddParity = findParity(odd);
    int evenParity = findParity(even);
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int k = 0, l = 0;

    unordered_map<int,int> pos;
    for (int i = 0; i < n; i++) pos[v[i]] = i;

    for (int i = 0; i < n - 3; i++) {
        if (i % 2 == 0) {
            int val = even[k];
            int idx = pos[val]; 
            if (v[i] > v[idx]) {
                swap(v[i], v[idx]);
                pos[v[idx]] = idx;
                pos[v[i]] = i;
            }
            k++;
        } else {
            int val = odd[l];
            int idx = pos[val];
            if (v[i] > v[idx]) {
                swap(v[i], v[idx]);
                pos[v[idx]] = idx;
                pos[v[i]] = i;
            }
            l++;
        }
    }

    if(oddParity!=evenParity){
        swap(v[n-1],v[n-3]);
    }
    
    printArray(v);
}

int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
