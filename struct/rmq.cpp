#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Range Maximum/Minimum Query with sparse table
// O(n log n) preprocessing, O(1) query
struct MaxInt {
    using T = long long;
    const T e = LLONG_MIN;
    T f(T a, T b) const { return max(a, b); }
};
struct MinInt {
    using T = long long;
    const T e = LLONG_MAX;
    T f(T a, T b) const { return min(a, b); }
};
struct GCDInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        return gcd(a, b);
    }
};
template <class B>
class RMQ : public B {
    using T = typename B::T;
    int n, lim;
    vector<vector<T>> spt;
private:
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = B::f(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a) : n(a.size()), lim(floor(log2(n)+1)) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = B::f(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};

int tt = 1, n, m;

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
