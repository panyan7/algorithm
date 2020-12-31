#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    bool operator < (const edge& o) {
        return w < o.w;
    }
};

int n;
vector<edge> edges;

vector<pair<int, int>> kruskal() {
    int cost = 0;
    vector<int> tree_id (n, 0);
    vector<pair<int, int>> res;
    for (int i = 1; i <= n; ++i)
        tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.w;
            res.push_back({e.u, e.v});

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 1; i <= n; ++i)
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
        }
    }
    return res;
}
