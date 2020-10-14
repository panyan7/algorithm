#include <bits/stdc++.h>
using namespace std;

vector<int> kahn_topo_sort(vector<vector<int>> G) {
    int n = G.size();
    vector<int> in_deg (n, 0);
    for (int i = 0; i < n; ++i) 
        for (int v : G[i])
            in_deg[v]++;
    queue<int> q;
    vector<int> res;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (in_deg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (int u : G[v])
            if (--in_deg[u] == 0)
                q.push(u);
        cnt++;
    }
    if (cnt == n)
        return res;
    else // exists cycle
        return vector<int> (0);
}
