#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]); // Optimizes depth 
}

bool union_sets(int v, int u) {
    v = find_set(v), u = find_set(u);
    if (v == u)
        return false;
    if (sz[v] < sz[u])
        swap(v, u); // Optimizes depth
    parent[u] = v;
    sz[v] += sz[u];
    return true;
}
