#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,psum=0,ssum=0,i,j;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
    }
    for(int i=0;i<n;i++){
        psum+=arr[i][i]; 
    }
    while(j>=0){
         ssum+=arr[i][j];
         i++;j--;
    }
           
    
    cout<<abs(psum-ssum);
}