#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N, M;
    cin >> N >> M;
    
    int freq[M + 1]= {};
    int a[N];
    for (int i= 0; i < N; i++) {       
        cin >> a[i];
    }
    for(int i=0;i<N;i++){
        freq[a[i]]++;  
    }

    for (int i = 1; i <= M; i++) {
        cout <<freq[i]<<endl;
    }
}

int main() {
    solve();
    return 0;
}

