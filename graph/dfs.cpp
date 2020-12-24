#include <bits/stdc++.h>
using namespace std;

int n = 100;
vector<vector<int>> G;
vector<bool> X (n, false);
vector<bool> A (n, false);

void dfs(int v) {
    int n = G.size();
    vector<int> s; s.push_back(v); X[v] = true;
    while (!s.empty()) {
        int u = s.back();
        s.pop_back();
        for (auto w : G[u]) {
            if (!X[w]) {
                s.push_back(w);
                X[w] = true;
            }
        }
    }
}

void dfs_rec(int v) {
    X[v] = true;
    for (auto u : G[v]) {
        if (!X[u]) dfs_rec(u);
    }
}

bool dfs_cycle(int v) {
    X[v] = true;
    A[v] = true;
    for (auto u : G[v]) {
        if (!X[u] && !dfs_cycle(u)) return false;
        else if (A[u]) return false;
    }
    A[v] = false;
    return true;
}
