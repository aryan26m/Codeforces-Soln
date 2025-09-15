#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)9e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
   cin>>n>>m>>k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i){
         cin >> vec[i];
    }
    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; int w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int s, e;
    cin >> s >> e;

    int sC = vec[s];
    if (sC > k) { 
        cout << -1 << '\n'; 
        return 0; 
    }
    vector<vector<int>> dist(n, vector<int>(k+1, INF));
    using T = tuple<int,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[s][sC] = 0;
    pq.emplace(0, s, sC);

    while (!pq.empty()) {
        auto t = pq.top(); pq.pop();
        int d = get<0>(t);
        int u = get<1>(t);
        int c = get<2>(t);
        if (d != dist[u][c]){ 
            continue;
        }
        if (u == e) { cout << d << '\n'; return 0; }
        for (auto &e : g[u]) {
            int v = e.first;
            int w = e.second;
            int nc = c + vec[v];
            if (nc > k){
                 continue;
                }
            if (dist[v][nc] > d + w) {
                dist[v][nc] = d + w;
                pq.emplace(dist[v][nc], v, nc);
            }
        }
    }

    int ans = INF;
    for (int c = 0; c <= k; ++c){
         ans = min(ans, dist[e][c]);
        }
    if (ans == INF){ 
        cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0;
}