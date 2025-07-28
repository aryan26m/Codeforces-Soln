#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int n) {
    if (n < 0) return false; // Negative numbers can't be perfect squares
    int sqrt_n = static_cast<int>(sqrt(n)); // Compute square root
    return sqrt_n * sqrt_n == n; // Verify if it's a perfect square
}
void solve(){
        int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int pro=a[0];
    // for(int i=1;i<n;i++){
    //     pro*=a[i];
    //     if(isPerfectSquare(pro)==false) {
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     else{
    //     }
    // }
    for(int i=0;i<n;i++){
        if(isPerfectSquare(a[i]) == false) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
    solve();
}
}