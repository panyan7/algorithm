#include <bits/stdc++.h>
using namespace std;

int n = 100;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> ancestor (n, false);

void dfs(int v) {
    stack<int> s;
    s.push(v);
    visited[v] = true;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (auto w : adj[u]) {
            if (!visited[w]) {
                s.push(w);
                visited[w] = true;
            }
        }
    }
}

void dfs_rec(int v) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs_rec(u);
}

bool dfs_cycle(int v) {
    visited[v] = true;
    ancestor[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u] && !dfs_cycle(u)) return false;
        else if (ancestor[u]) return false;
    }
    ancestor[v] = false;
    return true;
}
