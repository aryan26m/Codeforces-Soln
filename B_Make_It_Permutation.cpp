#include <bits/stdc++.h>
using namespace std;
#define ll long long
void countBits(int num) {
    int count0 = 0, count1 = 0;
    int totalBits = sizeof(int) * 8; // Total bits in an integer

    for (int i = 0; i < totalBits; i++) {
        if (num & (1 << i))
            count1++;
        else
            count0++;
            v.push_back(pow(2,i));
    }
}

int solve() {
    int n;
    cin>>n;
    int cnt=0;
    cout<<pow(2,3)<<endl;
    for(int i=1;i<=n;i++){
        if(i==1){
            cnt++;
        }
        else{
            cnt++;
            if(n-i+1>1){
                cnt++;
            }
        }
    }
    // cout<<cnt<<endl;
    for(int i=1;i<=n;i++){
        if(i==1){
            cout<<i<<" "<<i+1<<" "<<n<<endl;
        }
        else{
            cout<<i<<" "<<1<<" "<<i<<endl;
            if(n-i+1>1){
                cout<<i<<" "<<i+1<<" "<<n<<endl;
            }
        }
    }
    cout<<endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) { solve(); }
}


