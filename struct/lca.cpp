#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

struct LCA {
    int n, lim;
    vector<vector<int>> ancestor;
    vector<int> level;
private:
    void build(int v, int p, vector<vector<int>>& adj) {
        level[v] = level[p] + 1;
        ancestor[v][0] = p;
        for (int k = 1; k <= lim; ++k)
            ancestor[v][k] = ancestor[ancestor[v][k-1]][k-1];
        for (int u : adj[v])
            if (u != p)
                build(u, v, adj);
    }
public:
    LCA(vector<vector<int>>& adj) : n((int)adj.size()), lim((int)log(n)+1) {
        build(1, 0, adj);
    }
    int query(int u, int v) {
        if (level[u] > level[v])
            swap(u, v);
        for (int k = lim; k >= 0; --k)
            if (level[ancestor[v][k]] >= level[u])
                v = ancestor[v][k];
        if (u == v)
            return u;
        for (int k = lim; k >= 0; --k) {
            if (ancestor[v][k] != ancestor[u][k]) {
                u = ancestor[u][k];
                v = ancestor[u][k];
            }
        }
        return ancestor[u][0];
    }
};

int t;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
