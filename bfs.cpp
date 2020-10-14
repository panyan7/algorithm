#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> G, int v) {
    int n = G.size();
    vector<bool> visited (n, false);
    queue<int> q; q.push(v); visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto w : G[u]) {
            if (!visited[w]) {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}
