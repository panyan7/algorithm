#include <bits/stdc++.h>
using namespace std;

struct edge { int u, v, w; };

const int INF = INT_MAX;
int n;
vector<vector<int>> d;
vector<edge> edges;

void floyd_warshall() {
    d.assign(n+1, vector<int> (n+1, INF));
    for (edge e : edges) {
        d[e.u][e.v] = e.w;
        d[e.v][e.u] = e.w;
    }
    for (int i = 1; i <= n; ++i) d[i][i] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
