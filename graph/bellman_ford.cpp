#include <bits/stdc++.h>
using namespace std;

struct edge { int u, v, w; };

const int INF = INT_MAX;
int n, m;
vector<edge> edges;
vector<int> d;

void bellman_ford(int s) {
    d.assign(n+1, INF);
    d[s] = 0;
    for (int k = 1; k <= n-1; ++k) {
        bool upd = false;
        for (edge e : edges) {
            if (d[e.u] < INF) {
                if (d[e.v] > d[e.u] + e.w) {
                    d[e.v] = d[e.u] + e.w;
                    upd = true;
                }
            }
        }
        if (!upd) return;
    }
}
