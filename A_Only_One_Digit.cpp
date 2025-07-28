
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t;
	cin >> t;

	while (t--) {

		ll n;
		cin >> n;
        ll p=INT_MAX;
        while (n>0)
        {
          p=min(p, n % 10);
            n=n/10;
            /* code */
        }
        
		cout << p << "\n";
	}


	return 0;
}
