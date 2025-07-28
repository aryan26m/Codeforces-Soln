#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
           string s;
           cin>>s;
           char f=s[0];
           char l=s[n-1];
           set<char>st;
           for(int i=1;i<n-1;i++){
            if(st.find(s[i]) != st.end() || s[i]==f || s[i]==l){
                cout<<"Yes"<<endl;
                return;
            }
            st.insert(s[i]);
           }
           cout<<"No"<<endl; 
}
int main(){
    int t;
    cin>>t;

    while(t-- ){
        solve();
    }
}