#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pt;
vector<vector<int>> G;
vector<bool> visited;
vector<int> tin, low;
int n, timer, num_bridges, num_comp;

void dfs(int v, int p) {
    visited[v] = true;
    tin[v] = timer; low[v] = timer; timer++;
    for (auto u : G[v]) {
        if (u == p) continue;
        if (visited[u]) low[v] = min(low[v], tin[u]);
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) num_bridges++;
        }
    }
}

void bridge(int v) {
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && !G[i].empty()) {
            num_comp++;
            dfs(i, -1);
        }
    }
}
