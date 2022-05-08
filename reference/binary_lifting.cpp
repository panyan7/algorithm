/*
 *  Reference solution using binary lifting on forest
 *  Codeforces 500 E "New Year Domino"
 *  https://codeforces.com/contest/500/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;

void solve() {
    cin >> n;
    vector<ll> p(n), l(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> l[i];
    stack<int> st;
    vector<int> nxt(n);
    vector<ll> rm(n);
    for (int i = n-1; i >= 0; i--) {
        ll mx = p[i] + l[i];
        while (!st.empty() && p[i] + l[i] >= p[st.top()]) {
            mx = max(mx, rm[st.top()]);
            st.pop();
        }
        rm[i] = mx;
        if (!st.empty())
            nxt[i] = st.top();
        else
            nxt[i] = n;
        st.push(i);
    }
    // binary lifting
    ll lim = ceil(log2(n)) + 1;
    vector<vector<int>> up(n+1, vector<int>(lim, n));
    vector<vector<ll>> cost(n+1, vector<ll>(lim, 0));
    for (int i = n-1; i >= 0; i--) {
        up[i][0] = nxt[i];
        if (nxt[i] < n)
            cost[i][0] = p[nxt[i]] - rm[i];
        for (int j = 1; j < lim; j++) {
            up[i][j] = up[up[i][j-1]][j-1];
            cost[i][j] = cost[i][j-1] + cost[up[i][j-1]][j-1];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ll res = 0;
        int u = x;
        for (int j = lim-1; j >= 0; j--) {
            if (up[u][j] <= y) {
                res += cost[u][j];
                u = up[u][j];
            }
        }
        cout << res << "\n";
    }
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
