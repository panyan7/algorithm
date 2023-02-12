#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// count number of x >= a, y >= b such that xy <= n, a,b > 0
ll count_xy(ll n, ll a, ll b) {
    ll res = 0;
    for (ll x = a; x <= (ll)ceil(sqrt(n)); x++) {
        // y > ceil(sqrt(n))
        ll lb = max((ll)ceil(sqrt(n))+1, b);
        ll ub = n/x;
        res += max(ub-lb+1, 0LL);
    }
    for (ll y = b; y <= (ll)ceil(sqrt(n)); y++) {
        ll lb = a;
        ll ub = n/y;
        res += max(ub-lb+1, 0LL);
    }
    return res;
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
