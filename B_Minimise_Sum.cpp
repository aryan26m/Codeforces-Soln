#include <iostream>
#include <vector>
#include <numeric> // for std::gcd and std::lcm in C++17
using namespace std;

// If not using C++17, define gcd and lcm manually:
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int ans = 1;
    for (int i = 0; i < n - 1; ++i) {
        int g = gcd(v[i], v[i + 1]);
        int x = v[i] / g;
        if (x != 1) {
            ans = lcm(x, ans);
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
