/**
 *  Reference Solution using Range Minimun Query
 *  Codeforces 1473 D "Program"
 *  https://codeforces.com/contest/1473/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

template <typename T, class Compare = less<T>>
class RMQ : private Compare {
    vector<vector<T>> spt;
    Compare compare;
    int n, lim;
private:
    const T& _compare(const T& a, const T& b) const {
        return Compare::operator()(a, b) ? a : b;
    }
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = _compare(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a, const Compare& comp_ = Compare()) :
        n(a.size()), lim(floor(log2(n)+1)), compare(comp_) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = _compare(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};

int t, n, m;

void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr (n+1, 0);
    for (int i = 1; i <= n; ++i)
        arr[i] = arr[i-1] + (s[i-1] == '+' ? 1 : -1);
    RMQ<int> mn(arr);
    RMQ<int, greater<int>> mx(arr);
    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        int mn1 = mn.query(0,l-1);
        int mx1 = mx.query(0,l-1);
        if (r == n) {
            cout << (mx1-mn1+1) << "\n";
            continue;
        }
        int mn2 = mn.query(r+1,n)-arr[r]+arr[l-1];
        int mx2 = mx.query(r+1,n)-arr[r]+arr[l-1];
        cout << (max(mx2,mx1)-min(mn2,mn1)+1) << "\n";
    }
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
