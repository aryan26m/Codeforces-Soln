#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<long long> dis(n + 1, 1e18);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    dis[1] = 0;
    int x = -1; // will store vertex involved in last relaxation

    for (int i = 1; i <= n; i++) {
        x = -1;
        for (int u = 1; u <= n; u++) {
            for (auto edge : adj[u]) {
                int v = edge.F;
                int w = edge.S;
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    parent[v] = u;
                    x = v; // store last updated vertex
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        x = parent[x];
    }

    vector<int> cycle;
    int cur = x;
    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != x && cur != -1);

    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int node : cycle) cout << node << " ";
    cout << "\n";
}

int main() {
    solve();
}
