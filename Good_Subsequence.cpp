#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
    cin>>n;
    vector<int> v(n);
 for(int i=0;i<n;i++){
    cin>>v[i];
 }
 if(n==0){
    cout<<0<<endl;
 }
 else{
     int cnt = 1; 
     int check = v[0] % 2;
     for (int i = 1; i < n; i++) {
         if (v[i] % 2 != check) {
             cnt++;
             check = v[i] % 2;   
         }
        }
     cout<<cnt<<endl;   
    }
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}