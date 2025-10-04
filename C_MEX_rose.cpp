#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int user_logic(const string &s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int max_len = 0;

    for (int start = 0; start < 2; start++) {
        int sum = 0;
        for (int i = start; i < 26; i += 2) {
            sum += freq[i];
        }
        max_len = max(max_len, sum);
    }

    return max_len;
}

int main() {
    string s;
    cin >> s;

    int max_length = user_logic(s);
    int result = (max_length > 1 && is_prime(max_length)) ? 1 : 0;
    cout << result << endl;

    return 0;
}