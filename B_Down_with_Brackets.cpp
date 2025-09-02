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

vi inputArray(int n) {
    vi a(n);
    for (int &x : a) cin >> x;
    return a;
}

void printArray(const vi &a) {
    for (int x : a) cout << x << ' ';
    cout << '\n';
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

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

bool comp(int a, int b) {
    return a > b;
}

void push(map<int, int> &mp, int k, int v) {
    mp[k] += v;
}

void solve() {
    string s;
    cin>>s;
    int n=s.size();
bool bal=true;
int cnt=0;
    for(int i=1;i<n-1;i++){
        if (s[i]=='('){
            cnt++;
        }
        else{
            cnt--;
        }
        if(cnt<0){
            bal=false;
            break;
        }
    }
    if(cnt!=0){
        bal=false;
    }

    if(bal){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
