#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T, class Compare = less<T>>
class RMQ {
    vector<vector<T>> spt;
    int n, lim;
private:
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T> (n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = Compare(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a) : n(a.size()), lim(floor(log2(n)+1)) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        return Compare(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

int t = 1, n, m, k, q;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
