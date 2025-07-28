#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve() {
   int n,k;
   cin>>n>>k;
   string s;
   for(int i=0;i<k;i++){
    s.push_back('1');
   }
   for(int i=k;i<n;i++){
    s.push_back('0');
   }
   cout<<s<<endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) { solve(); }
}


