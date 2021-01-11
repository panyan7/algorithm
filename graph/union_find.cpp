#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> sz;

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (parent[v] == v) return v;
    return find_set(parent[v]);
}

bool union_sets(int v, int u) {
    v = find_set(v), u = find_set(u);
    if (v == u) return false;
    parent[u] = v;
    sz[v] += sz[u];
    return true;
}
