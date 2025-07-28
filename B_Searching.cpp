#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k;
    cin>>n;
    long int arr[n];
    for(long long int i=0;i<n;i++)
    cin>>arr[i];
    cin>>k;
    long long ans=-1;
    for(long int i=0;i<n;i++)
    {
       if(arr[i]==k)
       {
        ans=i;
        break;
       }
    }
    
    cout<<ans<<endl;
    return 0;

}