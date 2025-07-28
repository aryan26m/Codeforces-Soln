#include <bits/stdc++.h>
using namespace std;

// Score simulation
int get_score(const vector<int>& A) {
    int a = A[0], b = A[1];
    for (int i = 2; i < A.size(); ++i) {
        int g1 = __gcd(a, A[i]);
        int g2 = __gcd(b, A[i]);
        if (g1 <= g2) a = b;
        b = A[i];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;

        if (X == Y) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> res;

        // Create list excluding X and Y
        vector<int> candidates;
        for (int i = 1; i <= N; ++i)
            if (i != X && i != Y)
                candidates.push_back(i);

        // Try putting strong z first: gcd(z, X) > gcd(X, Y)
        int gx = __gcd(X, Y);
        int z = -1;
        for (int val : candidates) {
            if (__gcd(val, X) > gx) {
                z = val;
                break;
            }
        }

        bool solved = false;

        if (z != -1) {
            // Put z in front
            vector<int> A = {z};
            for (int val : candidates)
                if (val != z)
                    A.push_back(val);
            A.push_back(Y);
            A.push_back(X);

            if (get_score(A) != Y) {
                for (int x : A) cout << x << ' ';
                cout << '\n';
                solved = true;
                continue;
            }
        }

        // Try ascending order
        vector<int> A;
        for (int val : candidates) A.push_back(val);
        A.push_back(Y);
        A.push_back(X);
        if (get_score(A) != Y) {
            for (int x : A) cout << x << ' ';
            cout << '\n';
            continue;
        }

        // Try descending order
        reverse(candidates.begin(), candidates.end());
        A.clear();
        for (int val : candidates) A.push_back(val);
        A.push_back(Y);
        A.push_back(X);
        if (get_score(A) != Y) {
            for (int x : A) cout << x << ' ';
            cout << '\n';
            continue;
        }

        // Impossible
        cout << -1 << '\n';
    }
    return 0;
}
