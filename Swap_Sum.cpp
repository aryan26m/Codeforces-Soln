#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// Each node stores the score contribution and next state
// for each of the two possible entry states.
struct Node {
    ll add[2];
    int nxt[2];
};

int N;
ll K;
vector<ll> A, B;
vector<Node> tree;

// Creates a leaf node based on the values at index i
Node make_leaf(int i) {
    Node leaf;

    // Case 1: Enter in State 0 (A, B)
    if (A[i] + K < B[i]) { // Swap occurs
        leaf.add[0] = B[i];
        leaf.nxt[0] = 1; // Exit in State 1
    } else { // No swap
        leaf.add[0] = A[i];
        leaf.nxt[0] = 0; // Exit in State 0
    }

    // Case 2: Enter in State 1 (B, A)
    if (B[i] + K < A[i]) { // Swap occurs (back to original)
        leaf.add[1] = A[i];
        leaf.nxt[1] = 0; // Exit in State 0
    } else { // No swap
        leaf.add[1] = B[i];
        leaf.nxt[1] = 1; // Exit in State 1
    }

    return leaf;
}

// Merges two child nodes by composing their state transitions
Node merge(const Node& left, const Node& right) {
    Node parent;

    // Compose for starting state 0
    parent.add[0] = left.add[0] + right.add[left.nxt[0]];
    parent.nxt[0] = right.nxt[left.nxt[0]];

    // Compose for starting state 1
    parent.add[1] = left.add[1] + right.add[left.nxt[1]];
    parent.nxt[1] = right.nxt[left.nxt[1]];

    return parent;
}

// Standard segment tree build
void build(int node_idx, int start, int end) {
    if (start == end) {
        tree[node_idx] = make_leaf(start);
    } else {
        int mid = start + (end - start) / 2;
        build(2 * node_idx, start, mid);
        build(2 * node_idx + 1, mid + 1, end);
        tree[node_idx] = merge(tree[2 * node_idx], tree[2 * node_idx + 1]);
    }
}

// Standard segment tree update
void update(int node_idx, int start, int end, int p) {
    if (start == end) {
        tree[node_idx] = make_leaf(p);
    } else {
        int mid = start + (end - start) / 2;
        if (start <= p && p <= mid) {
            update(2 * node_idx, start, mid, p);
        } else {
            update(2 * node_idx + 1, mid + 1, end, p);
        }
        tree[node_idx] = merge(tree[2 * node_idx], tree[2 * node_idx + 1]);
    }
}

void solve() {
    cin >> N >> K;
    A.assign(N, 0);
    B.assign(N, 0);
    tree.assign(4 * N, Node());

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    build(1, 0, N - 1);

    int Q;
    cin >> Q;
    while (Q--) {
        int type, p;
        ll x;
        cin >> type >> p >> x;
        p--; // 0-indexed

        if (type == 1) {
            A[p] = x;
        } else {
            B[p] = x;
        }
        update(1, 0, N - 1, p);

        // The answer is the score from starting in state 0 at the root.
        cout << tree[1].add[0] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}