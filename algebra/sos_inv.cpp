#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

template <class T_in, class T_out>
vector<T_out> inverse_sum_over_subsets(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i];
    for (int i = 0; i < n; i++)
        for (int base = 0; base < (1 << n); base += (1 << (i+1)))
            for (int mask = base; mask < base + (1 << i); mask++)
                f[mask + (1 << i)] -= f[mask];
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) % 2 == 0)
            f[mask] = 0-f[mask];
    }
    return f;
}

// check long long
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
