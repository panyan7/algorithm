#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
const int MAXN = 1e5;
ll g[MAXN+10];

void solve() {
    cin >> n >> m;
    for (int d = min(m, n); d >= 1; d--) {
        g[d] = (n / d) * (m / d);
        for (int k = 2; k <= min(m, n) / d; k++)
            g[d] -= g[k * d];
    }
    // g[d] is number of pairs x,y such that
    // 1 <= x <= n, 1 <= y <= m, and gcd(x,y) = d
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
