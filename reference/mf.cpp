/**
 *  Reference solution using Dinic's algorithm for Max Flow
 *  Codeforces 1426 E "Rock, Paper, Scissors"
 *  https://codeforces.com/problemset/problem/1426/E
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int u, int v, long long cap) : u(u), v(v), cap(cap) {}
};
struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, long long cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].v] != -1)
                    continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int u, long long pushed) {
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
}; 

int t = 1, n, m, k;

void solve() {
    cin >> n;
    array<int,3> a, b;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++)
        cin >> b[i];
    Dinic D(8, 0, 7);
    D.add_edge(0, 1, b[0]);
    D.add_edge(0, 2, b[1]);
    D.add_edge(0, 3, b[2]);
    D.add_edge(1, 4, min(b[0], a[0]));
    D.add_edge(1, 5, min(b[0], a[1]));
    D.add_edge(2, 5, min(b[1], a[1]));
    D.add_edge(2, 6, min(b[1], a[2]));
    D.add_edge(3, 6, min(b[2], a[2]));
    D.add_edge(3, 4, min(b[2], a[0]));
    D.add_edge(4, 7, a[0]);
    D.add_edge(5, 7, a[1]);
    D.add_edge(6, 7, a[2]);
    Dinic E(8, 0, 7);
    E.add_edge(0, 1, a[0]);
    E.add_edge(0, 2, a[1]);
    E.add_edge(0, 3, a[2]);
    E.add_edge(1, 5, min(a[0], b[1]));
    E.add_edge(2, 6, min(a[1], b[2]));
    E.add_edge(3, 4, min(a[2], b[0]));
    E.add_edge(4, 7, b[0]);
    E.add_edge(5, 7, b[1]);
    E.add_edge(6, 7, b[2]);
    cout << n - D.flow() << "\n";
    cout << E.flow() << "\n";
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
