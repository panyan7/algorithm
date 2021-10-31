#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct MinCostFlow {
    vector<vector<int>> adj, cost, cap;
    const int INF = 1e9;
    int n, k, s, t;
    MinCostFlow(int n, int k, int s, int t) : n(n), k(k), s(s), t(t) {
        adj.assign(n, vector<int>());
        cost.assign(n, vector<int>(n, 0));
        cap.assign(n, vector<int>(n, 0));
    }
    void add_edge(int u, int v, long long cap_, long long cost_) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u][v] = cost_;
        cost[v][u] = -cost_;
        cap[u][v] = cap_;
    }
    void shortest_paths(int v0, vector<int>& d, vector<int>& p) {
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
            for (int v : adj[u]) {
                if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                    d[v] = d[u] + cost[u][v];
                    p[v] = u;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    int flow() {
        int flow = 0;
        int cost = 0;
        vector<int> d, p;
        while (flow < k) {
            shortest_paths(s, d, p);
            if (d[t] == INF)
                break;
            // find max flow on that path
            int f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, cap[p[cur]][cur]);
                cur = p[cur];
            }
            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                cap[p[cur]][cur] -= f;
                cap[cur][p[cur]] += f;
                cur = p[cur];
            }
        }
        if (flow < k)
            return -1;
        else
            return cost;
    }
};

int tt = 1, n, m, k;

// check long long
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
