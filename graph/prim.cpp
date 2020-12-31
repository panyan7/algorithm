#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj; // adjacency matrix
const int INF = 0x3f3f3f3f;
// typedef pair<int, int> edge;

struct edge { int w = INF, to = 0; };

vector<pair<int, int>> prim() {
    int total = 0;
    vector<bool> selected (n+1, false);
    vector<edge> min_e(n+1);
    vector<pair<int, int>> res;
    min_e[1].w = 0;

    for (int i = 1; i <= n; ++i) {
        int v = 0;
        for (int j = 1; j <= n; ++j)
            if (!selected[j] && (v == 0 || min_e[j].w < min_e[v].w))
                v = j;

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            return res;
        }

        selected[v] = true;
        total += min_e[v].w;
        if (min_e[v].to != 0)
            res.push_back({v, min_e[v].to});
        for (int u = 1; u <= n; ++u)
            if (adj[v][u] < min_e[u].w)
                min_e[u] = {adj[v][u], v};
    }
    cout << total << endl;
    return res;
}
