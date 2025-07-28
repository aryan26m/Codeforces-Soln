#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long gelly_best = min(b, d + b);

        long long flower_best = min(a, c + a);

        if (gelly_best * 2 - 1 <= flower_best * 2)
            cout << "Gellyfish\n";
        else
            cout << "Flower\n";
    }
    return 0;
}
