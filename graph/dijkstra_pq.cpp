#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int INF = 1e9; // Large value, INT_MAX may cause overflow
vector<vector<pii>> adj;
vector<int> dist, p;

void dijkstra(vector<int>& source) {
    dist.assign(n, INF);
    p.assign(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int s : source) {
        pq.push({0, s});
        dist[s] = 0;
    }
    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (dist[v] != d) // Skip impossible paths
            continue;
        for (auto e : adj[v]) {
            int u = e.first, w = e.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
}

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
