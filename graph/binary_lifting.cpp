#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;

void solve() {
    cin >> n;
    // topological order 0, ..., n-1
    // add a pseudo-root for forest
    vector<int> parent(n);
    ll lim = ceil(log2(n)) + 1;
    vector<vector<int>> up(n, vector<int>(lim, n));
    vector<vector<ll>> cost(n, vector<ll>(lim, 0));
    for (int i = 0; i < n; i++) {
        up[i][0] = parent[i];
        for (int j = 1; j < lim; j++) {
            up[i][j] = up[up[i][j-1]][j-1];
            cost[i][j] = cost[i][j-1] + cost[up[i][j-1]][j-1];
        }
    }
    auto query = [&](int x) {
        ll res = 0;
        int u = x;
        for (int j = lim-1; j >= 0; j--) {
            if (up[u][j] <= y) {
                res += cost[u][j];
                u = up[u][j];
            }
        }
        return res;
    };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
