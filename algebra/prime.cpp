#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

vector<pll> factorize(ll n) {
    vector<pll> res;
    ll cnt = 0;
    while (n % 2 == 0)
        cnt++, n /= 2;
    if (cnt > 0)
        res.push_back({2, cnt});
    for (int i = 3; i <= sqrt(n); i += 2) {
        cnt = 0;
        while (n % i == 0)
            cnt++, n /= i;
        if (cnt > 0)
            res.push_back({i, cnt});
    }
    if (n != 1)
        res.push_back({n, 1});
    return res;
}

void solve() {
    ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
