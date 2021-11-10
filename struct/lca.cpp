#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

class LCA {
    int n, lim;
    vector<vector<int>> anc;
    vector<int> level;
private:
    void _build(int v, int p, const vector<vector<int>>& adj) {
        // binary lifting
        level[v] = level[p] + 1;
        anc[v][0] = p;
        for (int k = 1; k <= lim; ++k)
            anc[v][k] = anc[anc[v][k-1]][k-1];
        for (int u : adj[v])
            if (u != p)
                _build(u, v, adj);
    }
public:
    LCA(const vector<vector<int>>& adj) : n(adj.size()), lim(log(n)+1) {
        _build(1, 0, adj);
    }
    int query(int u, int v) const {
        if (level[u] > level[v])
            swap(u, v);
        for (int k = lim; k >= 0; --k)
            if (level[anc[v][k]] >= level[u])
                v = anc[v][k];
        if (u == v)
            return u;
        for (int k = lim; k >= 0; --k) {
            if (anc[v][k] != anc[u][k]) {
                u = anc[u][k];
                v = anc[u][k];
            }
        }
        return anc[u][0];
    }
};

int tt = 1, n, m;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
