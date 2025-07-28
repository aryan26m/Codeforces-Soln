#include <iostream>
#include <cmath>

using namespace std;

long long calculateSum(long long u, long long N) {
    long long sum = 0;
    long long current = u;
    long long steps = 0;

    while (current > 0 && steps < N) {
        sum += current;
        current /= 2; // Move to parent
        steps++;
    }

    return sum;
}

long long findStartingNode(long long X, long long N) {
    for (long long k = 1; k <= N; k++) {
        // Calculate the denominator
        double denominator = 2 - (1.0 / pow(2, k - 1));
        // Calculate u
        long long u = static_cast<long long>(X / denominator);
        
        // Check if u is valid
        if (u > 0 && (X % static_cast<long long>(denominator) == 0) && u <= 1e18) {
            // Verify the sum
            if (calculateSum(u, k) == X) {
                return u; // Found a valid starting node
            }
        }
    }
    
    return -1; // No valid starting node found
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long X, N;
        cin >> X >> N;
        long long result = findStartingNode(X, N);
        cout << result << endl;
    }
    
    return 0;
}