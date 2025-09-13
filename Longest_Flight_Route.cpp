#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(0);
const int INF = -1e18;

int n, m;
vector<vector<int>> adj;

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, {});

    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        indeg[b]++;
    }

    // Topological sort
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);

    vector<int> dist(n + 1, INF), parent(n + 1, -1);
    dist[1] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[u] != INF && dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
            if (--indeg[v] == 0) q.push(v);
        }
    }
    
    if (dist[n] == INF) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << dist[n] << "\n";
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur]) path.pb(cur);
    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    fast;
    solve();
    return 0;
}
