#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;
vector<vector<pair<int,ll>>> adj;

vector<ll> dijkstra(int n, int s) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        ll du = p.first;
        int u = p.second;
        if (du != dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[v] > du + w) {
                dist[v] = du + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        ll t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    auto dist = dijkstra(n, 1);

    vector<pair<ll,int>> v;
    v.reserve(k);
    for (int i = 0; i < k; i++) {
        int u;
        ll t;
        cin >> u >> t;
        v.push_back({t, u});
    }
    sort(v.begin(), v.end());

    for (auto &e : v) {
        ll t = e.first;
        int u = e.second;
        if (dist[u] <= t) {
            cout << t << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
