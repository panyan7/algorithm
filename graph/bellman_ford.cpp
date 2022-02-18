#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const int INF = 1e9;
int n, m;
vector<array<ll,3>> edges;
vector<int> d;

void bellman_ford(int s) {
    d.assign(n+1, INF);
    d[s] = 0;
    for (int k = 1; k <= n-1; ++k) {
        bool upd = false;
        for (auto e : edges) {
            if (d[e[0]] < INF) {
                if (d[e[1]] > d[e[0]] + e[2]) {
                    d[e[1]] = d[e[0]] + e[2];
                    upd = true;
                }
            }
        }
        if (!upd) return;
    }
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
