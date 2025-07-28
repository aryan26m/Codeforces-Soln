#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    
    int arr[n],brr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    cin>>brr[i];
    
    int ind=0,el=brr[0];
    for(int i=0;i<n;i++){
        if(arr[i]==el){
            ind=i;
            break;
        }
    }
    
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({abs(el-arr[i]),arr[i]});
    }
    
    sort(v.begin(),v.end());
    
    int cnt=0;
    for(int i=0;i<n;i++){
        if(brr[i]!=v[i].second){
            cnt=1;
            break;
        }
    }
    
    if(cnt==0)
    cout<<ind+1<<endl;
    else
    cout<<"-1"<<endl;
}
}