#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Edmonds-Karp with SPFA for min cost max flow
struct FlowEdge {
    int u, v;
    long long cap, cost, flow = 0;
    FlowEdge(int u, int v, long long cap, long long cost) : u(u), v(v), cap(cap), cost(cost) {}
};
struct MinCostFlow {
    vector<vector<int>> adj;
    vector<FlowEdge> edges;
    vector<pair<long long, long long>> ans;
    const long long INF = 1e18;
    int n, m = 0;
    int s, t;
    MinCostFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
    }
    void add_edge(int u, int v, long long cap_, long long cost_) {
        edges.emplace_back(u, v, cap_, cost_);
        edges.emplace_back(v, u, 0, -cost_);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    void shortest_paths(int v0, vector<long long>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id : adj[u]) {
                int v = edges[id].v;
                if (edges[id].cap > 0 && d[v] > d[u] + edges[id].cost) {
                    d[v] = d[u] + edges[id].cost;
                    p[v] = id;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    long long flow(long long k = -1) {
        if (k == -1) k = INF;
        long long flow = 0;
        long long cost = 0;
        vector<long long> d;
        vector<int> p;
        while (flow < k) {
            shortest_paths(s, d, p);
            if (d[t] == INF)
                break;
            long long f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, edges[p[cur]].cap);
                cur = edges[p[cur]].u;
            }
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                edges[p[cur]].flow += f;
                edges[p[cur]^1].flow -= f;
                edges[p[cur]].cap -= f;
                edges[p[cur]^1].cap += f;
                cur = edges[p[cur]].u;
            }
            ans.push_back({flow, cost});
        }
        if (k < INF && flow < k)
            return -1;
        else
            return cost;
    }
};

int tt = 1, n, m, k;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
