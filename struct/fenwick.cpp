#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

struct FenwickTree {
    vector<int> bit;
    int n;
    FenwickTree(int n_) : n(n_) { bit.assign(n, 0); }
    FenwickTree(const vector<int>& a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; ++i)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (int i = r; i >= 0; i = (i & (i+1)) - 1)
            ret += bit[i];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    void add(int idx, int delta) {
        for (int i = idx; i < n; i = i | (i + 1))
            bit[i] += delta;
    }
};

int tt = 1, n, m;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
