#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> tour;

void dfs(int v) {
    while (!adj[v].empty()) {
        int u = adj[v].back();
        adj[v].pop_back();
        dfs(u);
    }
    tour.push_back(u);
}
void euler_tour(int v) {
    dfs(v);
    reverse(tour.begin(), tour.end());
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
