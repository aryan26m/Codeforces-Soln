#include <bits/stdc++.h>
using namespace std;

void solve(){
int n;
cin>>n;
string s;
cin>> s;
int x=-1;
for(int i=0;i<n/2;i++){
    if(s[i]!=s[n-i-1]){
        x=i;
        break;
    }
}
if(x==-1){
    cout<<0<<endl;
    return;
}
else{
    int i=x;
    int j=n-x-1;
    int cnt1=0;

   while(s[i]==s[x]){
    i++;
    cnt1++;
   }
    if(s[i]==s[j]){
       
       while(i<j)  {
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            if(s[i]==s[x]){
                cnt1++;
                i++;
            }
            else if(s[j]==s[x]){
                cnt1++;
                j--;
            }
            else{
                cnt1=INT_MAX;
                break;
            }
        }
       } 
    }
    else{
        cnt1=INT_MAX;
    }
     i=x;
     j=n-x-1;
    int cnt2=0;
      while(s[j]==s[n-x-1]){
        j--;
        cnt2++;
    }
    
    if(s[i]==s[j]){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;

            }
            else{
                if(s[i]==s[n-x-1]){
                    i++;
                    cnt2++;
                }
                else if(s[j]==s[n-x-1]){
                    j--;
                    cnt2++;
                }
                else{
                    cnt2=INT_MAX;
                    break;
                }
            }
        }
    }
    else{
        cnt2=INT_MAX;
    }
    if(cnt1==INT_MAX && cnt2==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<min(cnt1,cnt2)<<endl;
    }
}
}
// void solve();
int main(){
    int t;
    cin>>t ;
while(t-- >0){
    solve();
}
}