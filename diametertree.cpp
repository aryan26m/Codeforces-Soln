#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

int n;
vvi g;

pair<int, vector<int>> bfs(int start) {
    vector<int> dist(n + 1, -1), par(n + 1, 0);
    queue<int> q;
    dist[start] = 0;
    par[start] = 0;
    q.push(start);

    int far = start;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] > dist[far]) far = u;
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return {far, par};
}

void solve() {
    cin >> n;
    g.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b); g[b].pb(a);
    }

    if (n == 1) { cout << 1 << "\n"; return; }

    pair<int, vector<int>> res1 = bfs(1);
    int u = res1.first;
    vector<int> _par1 = res1.second;

    pair<int, vector<int>> res2 = bfs(u);
    int v = res2.first;
    vector<int> par = res2.second;

    vector<int> dia;
    for (int x = v; x != 0; x = par[x]) dia.pb(x);
    reverse(dia.begin(), dia.end());

    int diasize = (int)dia.size();
    int len = diasize - 1;

    if (len % 2 == 1) {
        cout << -1 << endl;
    } else {
        cout << dia[diasize / 2] << endl;
    }
}

int32_t main() {
    fast;
    solve();
    return 0;
}