#include <iostream>
#include <vector>
#include <bits/stdc++.h>
// using namespace std;
using namespace std;
#define ll long long
vector<long long> factorsLessThanK(long long n) {
    vector<long long> result;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            result.push_back(i);
            if (n / i != i) result.push_back(n / i);
        }
    }
    return result;
}
int main() {
    long t;
    cin>>t;
    while(t-- ){
        long long n;
        cin >> n;
        vector<long long> f = factorsLessThanK(n);
        // sort(f.begin(),f.end());
        int x=f.size();
        bool ans=false;
        if(x>=2){
         for(int i=0;i<x;i++){
            for(int j=i+1;j<x;j++){
                ll a=f[i];
                ll b=f[j];
                ll c=n/(a*b);
                if(c>1 && c!=a &&c!=b && n==(a*b*c)){
                    cout<<"YES"<<endl;
                  cout<<a<<" "<<b<<" "<<c<<endl;
                  ans=true;
                  break;
                }
            }
            if(ans){break;}
         }
         if(ans==false){
             cout<<"NO"<<endl;
         }
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    }