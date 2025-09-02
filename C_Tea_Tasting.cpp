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

// Input array
vi inputArray(int n) {
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
int search(const vi&a,const vi&pre , int l, int h){
int ans=-1;
int rem;
if(l==0){
    rem=0;
}
else{
    rem=pre[l-1];
}
int find=a[l];
while(l<=h)
{
    int m=(l+h)/2;
    if((pre[m]-rem) >= find){
        ans=m;
        h=m-1;
    }
    else{
        l=m+1;
    }
}
// cout<<ans<<endl;
return ans;
}

void solve() {
    int n;
    cin>>n;
    vi v=inputArray(n);
    vi c=inputArray(n);
   vi pre(n);
    pre[0]=c[0];

    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+c[i];
    }
   vi ans(n);
   vi ans2(n);

//    ans[0]=min(c[0],v[0]);
    for(int i=0;i<n;i++){
        int idx=search(v,pre,i,n-1);
        if(idx==-1){
            ans[i]+=1;
        }
        else{
            if(idx==i){
                ans2[i]+=min(v[i],c[i]);
            }
            else{
                ans[i]++;
                ans[idx]--;
                if(i-1<0){
                    ans2[idx]+=abs(v[i]-pre[idx-1]);
                }
                else{
                    ans2[idx]+=abs(v[i]-(pre[idx-1]-pre[i-1]));
                }
            }
        }
    }
    // printArray(ans2);
    for(int i=1;i<n;i++){
        ans[i]=ans[i-1]+ans[i];
    }
    for(int i=0;i<n;i++){
        ans[i]=ans2[i]+(ans[i]*c[i]);
    }
    printArray(ans);
}

int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
