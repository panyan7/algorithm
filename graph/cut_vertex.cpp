#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis, cut;
vector<int> parent, disc, low;
int cur_time = 0;

void dfs(int v, int p) {
    int child_cnt = 0;
    vis[v] = true;
    disc[v] = low[v] = ++cur_time;
    for (int u : adj[v]) {
        if (!vis[u]) {
            child_cnt++;
            parent[u] = v;
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (p != -1 && low[u] >= disc[v])
                cut[v] = true;
        } else if (u != p) {
            low[v] = min(low[v], disc[u]);
        }
    }
    if (p == -1 && child_cnt > 1)
        cut[v] = true;
}

void solve() {
    cin >> n;
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
