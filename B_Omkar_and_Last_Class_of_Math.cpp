#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

ll largestProperFactor(ll n) {
    if (n <= 1) return 0;
    if (isPrime(n)) return 1;

    for (ll i = n / 2; i >= 1; --i)
        if (n % i == 0)
            return i;
    return 1;
}


void solve() {
    ll n;
    cin >>n;

    if(n%2==0){
        ll m=n/2;
        cout<<m<<" "<<m<<endl;
    }
    else{
        ll x =largestProperFactor(n);
        if(x==1){
            cout<<1<<" "<<n-1<<endl;
        }
        else{
            cout<<x<<" "<<n-x<<endl;

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
