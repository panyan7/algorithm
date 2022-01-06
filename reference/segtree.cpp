/**
 *  Reference solution using Segment Tree
 *  Codeforces 1478 E "Nezzar and Binary String"
 *  https://codeforces.com/contest/1478/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T>
class SegTree {
    int n;
    vector<T> tree;
    vector<bool> mark;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            mark[v] = true;
        } else {
            int tmid = tl + (tr - tl) / 2;
            _build(a, v*2, tl, tmid);
            _build(a, v*2+1, tmid+1, tr);
            tree[v] = 0;
        }
    }
    void _update(int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] = val;
            mark[v] = true;
            return;
        }
        if (mark[v]) {
            tree[v*2] = tree[v*2+1] = tree[v];
            mark[v*2] = mark[v*2+1] = true;
            mark[v] = false;
        }
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
    }
    T _sum(int v, int tl, int tr, int l, int r) {
        if (l > r || tr < l || tl > r)
            return 0;
        if (mark[v] && tr >= r && tl <= l)
            return tree[v] * (r-l+1);
        int tmid = tl + (tr - tl) / 2;
        return _sum(v*2, tl, tmid, l, min(r, tmid)) +
               _sum(v*2+1, tmid+1, tr, max(l, tmid+1), r);
    }
    T _get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return tree[v];
        if (mark[v])
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(const vector<T>& a) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, SegTree st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void update(int val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(int val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T sum(int l, int r)                { return _sum(1, 0, n-1, l, r); }
    T get(int pos)                     { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)              { return get(pos); }
};

int t = 1, n, m, k, q;

void solve() {
    cin >> n >> q;
    string s, f;
    cin >> s;
    cin >> f;
    vector<int> a (n, 0);
    for (int i = 0; i < n; ++i) {
        if (f[i] == '1')
            a[i] = 1;
    }
    SegTree<int> st (a);
    vector<int> lx (q, 0);
    vector<int> rx (q, 0);
    for (int i = 0; i < q; ++i) {
        cin >> lx[i] >> rx[i];
        --lx[i], --rx[i];
    }
    for (int i = q-1; i >= 0; --i) {
        int l = lx[i], r = rx[i];
        int cnt = st.sum(l, r);
        if (cnt * 2 > r-l+1)
            st.update(1, l, r);
        else if (cnt * 2 < r-l+1)
            st.update(0, l, r);
        else {
            cout << "NO\n";
            return;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (st.get(i) != (int)(s[i]-'0')) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

