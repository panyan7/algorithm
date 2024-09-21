#include <bits/stdc++.h>
using namespace std;

int tt = 1, n, m, q;

void solve() {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> tin, low;
    int timer, num_bridges, num_comp;
    auto dfs = [&](auto& dfs, int v, int p) -> void {
        visited[v] = true;
        tin[v] = timer; low[v] = timer; timer++;
        for (auto u : adj[v]) {
            if (u == p) continue;
            if (visited[u]) low[v] = min(low[v], tin[u]);
            else {
                dfs(dfs, u, v);
                low[v] = min(low[v], low[u]);
                if (low[u] > tin[v]) num_bridges++;
            }
        }
    };
    auto bridge = [&](int v) -> void {
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && !adj[i].empty()) {
                num_comp++;
                dfs(dfs, i, -1);
            }
        }
    };
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
