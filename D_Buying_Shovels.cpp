#include <iostream>
#include <vector>
#include <bits/stdc++.h>
// using namespace std;
using namespace std;

vector<long long> factorsLessThanK(long long n, long long k) {
    vector<long long> result;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i <= k) result.push_back(i);
            if (n / i != i && n / i <= k) result.push_back(n / i);
        }
    }
    return result;
}
int main() {
    long t;
    cin>>t;
    while(t-- ){
        long long n, k;
        cin >> n >> k;
        vector<long long> factors = factorsLessThanK(n, k);
        sort(factors.begin(),factors.end());
        long long s=factors.size();
        long long ans=factors[s-1];
        long long x=n/ans;
        cout<<x<< endl;
    }
    }