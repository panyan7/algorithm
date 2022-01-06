/**
 *  Reference solution using lowest common ancestor
 *  The problem directly asks if one node is the ancestor of the other.
 */
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
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    void print() {
        cout << "tin\n";
        for (int i = 0; i < n; i++)
            cout << tin[i] << " \n"[i+1==n];
        cout << "tout\n";
        for (int i = 0; i < n; i++)
            cout << tout[i] << " \n"[i+1==n];
        cout << "anc\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= lim; j++)
                cout << anc[i][j] << " \n"[j==lim];
        }

    }
public:
    LCA(int n_) : n(n_), lim(ceil(log(n_))) {
        tin.assign(n, 0);
        tout.assign(n, 0);
        adj.resize(n);
        anc.assign(n, vector<int>(lim+1, 0));
    }
    void init(int root = 0) {
        dfs(root, root);
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
};

int tt = 1, n, m, q;

void solve() {
    cin >> n >> q;
    LCA G(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.adj[u].push_back(v);
        G.adj[v].push_back(u);
    }
    G.init();
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int x = G.query(u, v);
        cout << (x == u ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
