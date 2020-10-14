#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> G, int v) {
    int n = G.size();
    vector<bool> visited (n, false);
    vector<int> s; s.push_back(v); visited[v] = true;
    while (!s.empty()) {
        int u = s.back();
        s.pop_back();
        for (auto w : G[u]) {
            if (!visited[w]) {
                s.push_back(w);
                visited[w] = true;
            }
        }
    }
}
