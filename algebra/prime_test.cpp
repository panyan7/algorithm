#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

ll mul_mod(ll a, ll b, ll mod) {
    return (__int128)a * b % mod;
}

ll pow_mod(ll a, ll e, ll mod) {
    ll res = 1;
    while (e) {
        if (e & 1)
            res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1;
    }
    return res;
}

bool check_composite(ll n, ll a, ll d, int r) {
    ll x = pow_mod(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int i = 1; i < r; i++) {
        x = mul_mod(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(ll n) {
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (n % a == 0)
            return false;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
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
