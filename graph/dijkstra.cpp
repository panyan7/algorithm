#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int INF = 1e9; // Large value, INT_MAX may cause overflow
vector<vector<pii>> adj;
vector<int> dist;

void dijkstra(int s) {
    /**
     * Single-source Djikstra's algorithm with priority queue.
     **/
    int n = adj.size();
    dist.assign(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;
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
