#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
const int INF = INT_MAX;
using edge = array<int,3>;

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<vector<pii>> adj;
    // make the adj list

    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    // d[i][j] shortest distance from i to j
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
