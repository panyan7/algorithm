#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj, adj_rev;
vector<bool> vis;
vector<int> order, components;
vector<vector<int>> res;

void dfs1(int v) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    vis[v] = true;
    components.push_back(v);
    for (int u : adj_rev[v])
        if (!vis[u])
            dfs2(u);
}

// check long long
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    vis.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs1(i);
    vis.assign(n, 0);
    reverse(order.begin(), order.end());
    for (int v : order) {
        if (!vis[v]) {
            dfs2(v);
            // the result is in components
            vector<int> temp;
            copy(components.begin(), components.end(), temp.begin());
            res.push_back(temp);
            components.clear();
        }
    }
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
