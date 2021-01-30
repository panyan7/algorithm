#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int v) {
    stack<int> s;
    s.push(v);
    vis[v] = true;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (auto w : adj[u]) {
            if (!vis[w]) {
                s.push(w);
                vis[w] = true;
            }
        }
    }
}

void dfs_rec(int v) {
    vis[v] = true;
    for (auto u : adj[v])
        if (!vis[u])
            dfs_rec(u);
}

