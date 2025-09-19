#include <bits/stdc++.h>
using namespace std;

vector<int> parent, color;
vector<bool> vis;

int find_next(int x) {
    if (x > (int)parent.size()-1) return x;
    if (parent[x] == x) return x;
    return parent[x] = find_next(parent[x]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    parent.resize(n+2);
    color.assign(n+1, 0);
    vis.assign(n+1, false);

    for (int i = 1; i <= n+1; i++) parent[i] = i;

    vector<tuple<int,int,int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        queries[i] = {l, r, c};
    }

    // process in reverse
    for (int i = q-1; i >= 0; i--) {
        int l, r, c;
        tie(l, r, c) = queries[i];
        int pos = find_next(l);
        while (pos <= r) {
            color[pos] = c;
            vis[pos] = true;
            parent[pos] = pos+1; // skip next time
            pos = find_next(pos);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
