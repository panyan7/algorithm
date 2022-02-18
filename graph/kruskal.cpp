#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<array<ll,3>> edges;
vector<int> parent;
vector<int> sz;

void init() {
    parent.resize(n);
    sz.assign(n, 1);
    for (int v = 0; v < n; ++v)
        parent[v] = v;
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

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    ll cost = 0;
    vector<array<ll,3>> res;
    for (array<ll,3> e : edges) {
        if (find_set(e[1]) != find_set(e[2])) {
            cost += e[0];
            res.push_back(e);
            union_sets(e[1], e[2]);
        }
        if (res.size() >= n-1)
            break;
    }
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
