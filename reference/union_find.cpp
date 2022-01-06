/**
 *  Reference solution using Dijkstra's Algorithm and Union Find
 *  Codeforces 1253 F "Cheap Robot"
 *  https://codeforces.com/contest/1253/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

const int64_t INF = 1e18;
int t = 1, n, m, k, q;
vector<vector<pll>> adj;
vector<ll> dist, res;
vector<int> parent, sz, query;
vector<vector<int>> token;
 
int find_set(int v) {
    if (parent[v] == v)
        return v;
    return find_set(parent[v]);
}
bool union_sets(int v, int u, ll cap) {
    u = find_set(u), v = find_set(v);
    if (u == v) return false;
    if (sz[v] < sz[u]) swap(u, v);
    for (int tk : token[u]) { // Move token to the new parent
        int other = tk^1;
        int i = tk/2;
        if (find_set(query[other]) == v)
            res[i] = cap;
        token[v].push_back(tk);
    }
    token[u] = vector<int> (0);
 
    sz[v] += sz[u];
    parent[u] = v;
    return true;
}
 
void solve() {
    cin >> n >> m >> k >> q;
    // Initialize vectors
    adj.resize(n);
    token.resize(n);
    dist.assign(n, INF);
    parent.assign(n, 0);
    sz.assign(n, 0);
    query.assign(2*q, 0);
    res.assign(q, 0);
    // Read graph
    vector<array<ll,3>> edges;
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    }
    // Multi-soure Dijkstra's algorithm
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int v = 0; v < k; ++v) {
        pq.push({0, v});
        dist[v] = 0;
    }
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (d != dist[v])
            continue;
        for (auto e : adj[v]) {
            ll u = e.first, w = e.second;
            if (dist[v]+w < dist[u]) {
                dist[u] = dist[v]+w;
                pq.push({dist[u], u});
            }
        }
    }
    // Compute the new weight of the edges
    for (auto& e : edges)
        e[0] += dist[e[1]] + dist[e[2]];
    sort(edges.begin(), edges.end());
    // Read query
    for (int i = 0; i < q; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        --n1, --n2;
        query[2*i] = n1, query[2*i+1] = n2;
        token[n1].push_back(2*i);
        token[n2].push_back(2*i+1);
    }
    // Union Find
    for (int v = 0; v < n; ++v) {
        parent[v] = v;
        sz[v] = 1;
    }
    for (auto e : edges)
        union_sets(e[2], e[1], e[0]);
    for (int i = 0; i < q; ++i)
        cout << res[i] << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
