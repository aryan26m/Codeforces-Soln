#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool allEqual = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                allEqual = false;
                break;
            }
        }

        if (allEqual) {
            cout << "YES\n";
            continue;
        }

        int xr = 0;
        for (int x : a) xr ^= x;
        if(xr==0){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            int cnt=0;
            int newxr=0;
           for(int x : a){
            newxr^=x;
            if(newxr==xr){
                cnt++;
                newxr=0;
            }
           }            
           if(cnt>2){
               cout<<"YES"<<endl;
continue;
           }         
      cout<<"NO"<<endl;
        }
    }

    return 0;
}
