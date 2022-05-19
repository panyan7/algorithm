#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> vis, anc, ord;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (auto u : adj[v]) {
        if (!vis[u] && !dfs(u))
            return false;
        else if (anc[u])
            return false;
    }
    anc[v] = false;
    ord.push_back(v);
    return true;
}
bool topological_sort() {
    //vis.assign(n, false);
    ord.clear();
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            bool res = dfs(i);
            if (!res)
                return false;
        }
    }
    reverse(ord.begin(), ord.end());
    return true;
}

void solve() {
    // first do topological sort
    // then do dp
    vector<int> dp(n, 1);
    for (int i = n-1; i >= 0; i--)
        for (int u : adj[ord[i]])
            dp[ord[i]] = max(dp[ord[i]], dp[u] + 1);
    int res = *max_element(dp.begin(), dp.end());
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
