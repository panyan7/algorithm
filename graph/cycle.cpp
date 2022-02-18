#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis, anc;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (anc[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    anc[v] = false;
    return false;
}

bool find_cycle() {
    vis.assign(n, 0);
    anc.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (!vis[v] && dfs(v))
            break;
    }
    if (cycle_start == -1) // acyclic
        return false;
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    return true;
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
