/**
 *  Reference solution using sum over subsets dp
 *  Codeforces 165 E "Compatible Numbers"
 *  https://codeforces.com/contest/165/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int res[8000001];

template<class T_in, class T_out>
vector<T_out> sum_over_subsets(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i], res[i] = i;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) {
                f[mask] += f[mask^(1<<i)];
                if (f[mask^(1<<i)] > 0)
                    res[mask] = res[mask^(1<<i)];
            }
        }
    }
    return f;
}

// check long long
void solve() {
    cin >> m;
    vector<int> a(m);
    n = ceil(log2(4000001));
    vector<int> cnt(1 << n, 0);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> f = sum_over_subsets<int,int>(cnt);
    for (int i = 0; i < m; i++) {
        int inv_mask = (~a[i])&((1<<n)-1);
        if (f[inv_mask] == 0)
            cout << "-1";
        else
            cout << res[inv_mask];
        cout << " \n"[i+1==m];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
