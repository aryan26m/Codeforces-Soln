#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n, -1);
    vector<bool> used(n, false);
    int num = 1;

    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;

        // Gather positions j such that j > i and (j - i) is a square
        vector<int> positions = {i};
        for (int k = 1; ; ++k) {
            int j = i + k*k;            // signed distance i - j = -k^2 if j>i,
            if (j >= n) break;          // but we only place forward so j>i
            positions.push_back(j);
        }

        if (positions.size() < 2) 
            continue;  // would be a singleton, skip

        // All positions must be free
        bool conflict = false;
        for (int j : positions)
            if (used[j]) { conflict = true; break; }
        if (conflict) 
            continue;

        // Assign the same number to all these positions
        for (int j : positions) {
            A[j] = num;
            used[j] = true;
        }
        ++num;
    }

    // If any position remains unfilled, no solution
    for (int x : A) {
        if (x < 0) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // Otherwise print the array
    for (int i = 0; i < n; ++i) {
        cout << A[i] << (i+1 < n ? ' ' : '\n');
    }
    return 0;
}
