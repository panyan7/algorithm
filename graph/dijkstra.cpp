#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const ll INF = 1e15; // Large value, INT_MAX may cause overflow
vector<vector<pll>> adj;
vector<ll> dist, p;

void dijkstra(vector<int>& source) {
    dist.assign(n, INF);
    p.assign(n, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int s : source) {
        pq.push({0, s});
        dist[s] = 0;
    }
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (dist[v] != d) // Skip impossible paths
            continue;
        for (auto e : adj[v]) {
            ll u = e.first, w = e.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
}
void dijkstra_dense(vector<int>& source) {
    dist.assign(n, INF);
    p.assign(n, -1);
    vector<bool> vis(n, 0);
    for (int s : source)
        dist[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }
        if (dist[v] == INF)
            break;
        vis[v] = true;
        for (auto e : adj[v]) {
            int u = e.first, w = e.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                p[u] = v;
            }
        }
    }
}


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
