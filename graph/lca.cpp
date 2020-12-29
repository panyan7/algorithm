#include <bits/stdc++.h>
using namespace std;

int n, l; // lim = log(n)
vector<vector<int>> G, anc;
vector<int> level;

void build(int v, int p) {
    level[v] = level[p] + 1;
    anc[v][0] = p;
    for (int k = 1; k <= l; ++k) {
        anc[v][k] = anc[anc[v][k-1]][k-1];
    }
    for (int u : G[v])
        if (u != p)
            build(u, v);
}

void preprocess() {
    build(1, 0);
}

int lca(int u, int v) {
    if (level[u] > level[v])
        swap(u, v);
    for (int k = l; k >= 0; --k) {
        if (level[anc[v][k]] >= level[u]) {
            v = anc[v][k];
        }
    }
    if (u == v)
        return u;
    for (int k = l; k >= 0; --k) {
        if (anc[v][k] != anc[u][k]) {
            u = anc[u][k];
            v = anc[u][k];
        }
    }
    return anc[u][0];
}

