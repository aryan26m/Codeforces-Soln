#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n][m];
int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin>>a[i][j];
        maxi=max(maxi,a[i][j]);
        }
    }

    int maxcnt=0;
    int row=0;
    int maxcol=0;
    int col=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(a[i][j]==maxi){
              cnt++;
              if(cnt>maxcnt){
                maxcnt=cnt;
                row=i;
              }
            }
        }
    }
    for(int i=m-1;i>=0;i--){
        int cnt=0;
        for(int j=0;j<n;j++){
             if(a[j][i]==maxi){
              cnt++;
              if(cnt>maxcol){
                maxcol=cnt;
                col=i;
              }
        }
    }
}
if(maxcnt==1){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==maxi){
                // cout<<i<<" " <<j<<endl;
                if(j!=col){
                    row=i; break;
                }
            }
        }
    }
}
if(maxcol==1){
 for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==maxi){
                if(i!=row){
                    col=j; break;
                }
            }
        }
    }
}
bool ans=true;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(a[i][j]==maxi){
            if(i!=row && j!=col){
                ans=false;
            }
        }
    }
}
if(ans==true)
{
    cout<<maxi-1<<endl;
}
else{
    cout<<maxi<<endl;
}
}

int main(){
    int t;
    cin>>t;

    while(t-- ){
        solve();
    }
}