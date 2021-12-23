#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

int tt = 1, n, m;

void solve() {
    cin >> n;
    vector<pll> a(n);
    for (auto& x : a)
        cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first < a[i].first) {
            pq.pop();
            // do stuff
        }
        pq.push({a[i].second, i});
        // do stuff
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
