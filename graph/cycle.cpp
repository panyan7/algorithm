#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis, anc;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (auto u : adj[v]) {
        if (!vis[u] && !dfs(u))
            return false;
        else if (anc[u])
            return false;
    }
    anc[v] = false;
    return true;
}
