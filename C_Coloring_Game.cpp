#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fii(const vector<ll>& v, ll sum, ll start) {
    int n=v.size();
    ll low = start, high = v.size() - 1;
    ll ans = v.size();
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        // cout<<"mid: "<<mid<<" low: "<<low<<" high: "<<high<<endl;
        if (sum + v[mid] <= v[n - 1]) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    } 
    sort(v.begin(), v.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long sum = v[i] + v[j];
              auto it = lower_bound(v.begin() + j + 1, v.end(), sum);
            //   cout <<*it<<endl;
            int index = it - v.begin() - 1;
            //   cout <<index<<endl;
 
              if(it == v.end() ) {
                 ans+= (n - j - 1); // Count of elements ≥ sum
            } else {
                int index = it - v.begin() - 1;
                if(index > j && sum+v[index]>v[n-1] ) {
                    ans += (index-j); // Count of elements ≥ sum
                    ll x=fii(v,( v[i]+v[j]),j+1);
                    if(x<n){
                        ans=ans-(x-j);
                    }
                }
            }
            }
        }
    cout<<ans<<endl;
    

}
int main(){
 int t;
 cin>>t;
 while(t--){
    solve();
 }
}