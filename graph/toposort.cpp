#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, ord;

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u])
            dfs(u);
    ord.push_back(v);
}
