#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--){
int n;
cin>>n;

int arr[n];
map<int,int>mp;
 
for(int i=0;i<n;i++){
    cin>>arr[i];
}
if(n<8){
    cout<<"0"<<endl;
    continue;
}
 
int cnt=0,i=0;
int cnt0=0,cnt1=0,cnt3=0,cnt2=0,cnt5=0;
for(i=0;i<n;i++){
    mp[arr[i]]++;
    
    if(mp[0]==3) cnt0=1;
    if(mp[1]==1) cnt1=1;
    if(mp[2]==2) cnt2=1;
    if(mp[3]==1) cnt3=1;
    if(mp[5]==1) cnt5=1;
 
    if(cnt0&&cnt1&&cnt2&&cnt3&&cnt5){
        cnt=1;
        break;
    }
}
 
if(cnt==1)
cout<<(i+1)<<endl;
else
cout<<"0"<<endl;
 
}
}