#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        int N, K;
        string S;
        cin >> N >> K;
        cin >> S;
        if(S[K-1] != '1'){
            cout << -1 << '\n';
            continue;
        }
        vector<int> prev(N+1), nextt(N+1);
        for(int i=1;i<=N;i++){
            prev[i] = (i==1? N : i-1);
            nextt[i] = (i==N? 1 : i+1);
        }
        vector<int> ans;
        ans.reserve(N);
        ans.push_back(K);
        int score = 1; 
        int L = prev[K];
        int R = nextt[K];
        nextt[prev[K]] = nextt[K];
        prev[nextt[K]] = prev[K];
        bool ok = true;
        for(int move = 2; move <= N; ++move){
            if(L == R){ 
                int choice = L;
                ans.push_back(choice);
                int c = (S[choice-1]=='1');
                if(move % 2 == 1) score += c;
                else score -= c;
                if(score <= 0) ok = false;
                break;
            }
            int bitL = S[L-1] - '0';
            int bitR = S[R-1] - '0';
            int choice = -1;
            if(move % 2 == 0){
                if(score == 1){
                    if(bitL == 0) choice = L;
                    else if(bitR == 0) choice = R;
                    else { ok = false; break; }
                } else {
                    if(bitL == 1) choice = L;
                    else if(bitR == 1) choice = R;
                    else choice = L;
                }
            } else {
                if(bitL == 1) choice = L;
                else if(bitR == 1) choice = R;
                else choice = L;
            }
            ans.push_back(choice);
            int c = (S[choice-1] == '1');
            if(move % 2 == 1) score += c;
            else score -= c;
            if(score <= 0){ ok = false; break; }
            int newL = prev[choice];
            int newR = nextt[choice];
            nextt[prev[choice]] = nextt[choice];
            prev[nextt[choice]] = prev[choice];
            L = newL;
            R = newR;
        }
        if(!ok) {
            cout << -1 << '\n';
        } else {
            for(int i=0;i<ans.size();++i){
                if(i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
