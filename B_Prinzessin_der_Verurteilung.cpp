#include <bits/stdc++.h>
using namespace std;

void generateStrings(int length, int maxLength, const vector<char>& characters, string current, unordered_set<string>& hs, bool &found) {
    if (length > maxLength) return;

    if (current.size() == length && hs.find(current) == hs.end()) {
        if (!found) { // Ensuring only the first valid string per test case is printed
            cout << current << endl;
            found = true;
        }
        return;
    }

    if (current.size() < length) {
        for (char ch : characters) {
            generateStrings(length, maxLength, characters, current + ch, hs, found);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<string> hs;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            int len = min(i, n - j);
            string sub = s.substr(j, len);
            hs.insert(sub);
        }
    }

    vector<char> characters;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        characters.push_back(ch);
    }

    int maxLength = 3;
    bool found = false;
    for (int length = 1; length <= maxLength; length++) {
        generateStrings(length, maxLength, characters, "", hs, found);
        if (found) break;
    }
}
int main(){
    int t;
    cin>>t;
    while(t-->0){  
    solve();
}
}

