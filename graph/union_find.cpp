#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;

struct UnionFind {
    int n;
    vector<int> parent, sz;
    UnionFind(int n_) : n(n_) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int v = 0; v < n; ++v)
            parent[v] = v;
    }
    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
    bool union_sets(int v, int u) {
        v = find_set(v), u = find_set(u);
        if (v == u)
            return false;
        if (sz[v] < sz[u])
            swap(v, u);
        parent[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

void solve() {
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
