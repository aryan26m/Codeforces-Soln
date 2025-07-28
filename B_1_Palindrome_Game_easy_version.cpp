#include <bits/stdc++.h>
using namespace std;
bool nozero(const string& s) {
    int n = s.size();
    for (int i = 0; i <= n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
        else if(s[i]=='0' || s[n - i - 1]=='0'){
            return false;
        }
    }
    return true;
}
string solve(){
int n;string s;
cin>>n>>s;
int cnt=0;
for(int i=0;i<n;i++){
    if(s[i]=='0'){
        cnt++;
    }
}
if(nozero(s)){
    return "DRAW";
}
if(n==1){
    return "BOB";
}
if(n%2==0){
    return "BOB";
}
else{
    if(s[n/2]=='0'){
        if(cnt>1){
            return "ALICE";
        }
        else{
            return "BOB";
        }
    }
    else{
        return "BOB";
    }
}
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}