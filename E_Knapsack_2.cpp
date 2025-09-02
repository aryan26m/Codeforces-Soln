#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        // Sort the array to easily get two smallest elements
        sort(arr.begin(), arr.end());

        // First option: sum of two smallest
        int option1 = arr[0] + arr[1];

        // Second option: minimum of arr[i] + arr[i+1]/2 over all adjacent pairs
        int option2 = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            option2 = min(option2, arr[i] + arr[i+1]/2);
        }

        cout << min(option1, option2) << endl;
    }
}
