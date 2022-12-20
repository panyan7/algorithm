#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Lowest common ancestor with binary lifting
// O(n log n) build and O(log n) query
// The graph needs to be undirected
struct LCA {
    int n, lim;
    int timer = 0;
    vector<vector<int>> anc;
    vector<vector<int>> adj;
    vector<int> tin, tout;
private:
    void dfs(int v, int p) {
        tin[v] = ++timer;
        anc[v][0] = p;
        for (int i = 1; i <= lim; ++i)
            anc[v][i] = anc[anc[v][i-1]][i-1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        tout[v] = ++timer;
    }
public:
    LCA(int n_) : n(n_), lim(ceil(log2(n_))) {
        tin.assign(n, 0);
        tout.assign(n, 0);
        adj.resize(n);
        anc.assign(n, vector<int>(lim+1, 0));
    }
    LCA(const vector<vector<int>>& adj_, int root = 0)
        : n(adj_.size()), adj(adj_), lim(ceil(log2(adj_.size()))) {
        tin.assign(n, 0);
        tout.assign(n, 0);
        anc.assign(n, vector<int>(lim+1, 0));
        init(root);
    }
    void init(int root = 0) {
        dfs(root, root);
    }
    int get_parent(int v) {
        return anc[v][0];
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int query(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = lim; i >= 0; --i) {
            if (!is_ancestor(anc[u][i], v))
                u = anc[u][i];
        }
        return anc[u][0];
    }
    // Get the child of u that is an ancestor of v
    int get_child(int u, int v) {
        assert(is_ancestor(u, v));
        for (int i = lim; i >= 0; --i) {
            if (!is_ancestor(anc[v][i], u))
                v = anc[v][i];
        }
        return v;
    }
};

int tt = 1, n, m, q;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
