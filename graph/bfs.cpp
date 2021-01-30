#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void bfs(int v) {
    int n = adj.size();
    vector<bool> vis (n, false);
    queue<int> q; q.push(v); vis[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto w : adj[u]) {
            if (!vis[w]) {
                q.push(w);
                vis[w] = true;
            }
        }
    }
}
