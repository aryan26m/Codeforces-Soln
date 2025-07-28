#include <bits/stdc++.h>
using namespace std;

long long maxLCTSubseq(string s) {
    int n = s.size();

    vector<long long> preL(n+1, 0), preLC(n+1, 0);

    vector<long long> sufT(n+1, 0),sufCT(n+1, 0);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            preL[i+1] = preL[i] + 1;
        } else {
            preL[i+1] = preL[i];
        }
        preLC[i+1] = preLC[i];
        if (s[i] == 'C') {
            preLC[i+1] += preL[i];
        }
    }

    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'T') {
            sufT[i] = sufT[i+1] + 1;
        } else {
            sufT[i] = sufT[i+1];
        }
        sufCT[i] =sufCT[i+1];
        if (s[i] == 'C') {
           sufCT[i] += sufT[i+1];
        }
    }
    
    long long strt = 0;
    for (int i = 0; i < n; i++) {

        if (s[i] == 'T') {
        
            strt += preLC[i];
        
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, preL[i] * sufT[i]);
        ans = max(ans,sufCT[i]);
        ans = max(ans, preLC[i]);
    }

    return strt + ans;
}
