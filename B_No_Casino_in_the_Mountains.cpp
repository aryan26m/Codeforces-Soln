#include <iostream>
#include <vector>
using namespace std;
void solve(){
     int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int count = 0;
        int i = 0;

        while (i + k <= n) {

            bool check = true;
            for (int j = 0; j < k; ++j) {
            
                if (a[i + j] == 1) {
            
                    check = false;
                    break;
                }
            }
            if (check) {
                count++;
                i += k + 1; 
           
            }
             else {
                i++;
            }
        
        }

        cout << count << '\n';
    }
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
       solve();
}
}
