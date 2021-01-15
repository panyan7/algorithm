#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void bfs(int v) {
    int n = adj.size();
    vector<bool> visited (n, false);
    queue<int> q; q.push(v); visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto w : adj[u]) {
            if (!visited[w]) {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}
