#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
 
/* Segment tree with range flip query and range sum query */
template <typename T>
struct SegTree {
    int n;
    vector<T> tree;
    vector<bool> mark;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
    void _push(int v, int tl, int tr) {
        if (mark[v]) {
            tree[v] = -tree[v];
            if (tl != tr) {
                mark[v*2] = !mark[v*2];
                mark[v*2+1] = !mark[v*2+1];
            }
            mark[v] = false;
        }
    }
    void _update(int v, int tl, int tr, int l, int r) {
        _push(v, tl, tr);
        if (tl > tr || tr < l || tl > r)
            return;
        if (l <= tl && r >= tr) {
            mark[v] = true;
            _push(v, tl, tr);
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid));
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
    T _query(int v, int tl, int tr, int l, int r) {
        if (l > r || tr < l || tl > r)
            return 0;
        _push(v, tl, tr);
        if (tr <= r && tl >= l)
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        return _query(v*2, tl, tmid, l, min(r, tmid)) +
               _query(v*2+1, tmid+1, tr, max(l, tmid+1), r);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        vector<T> a(n, 0);
        _build(a, 1, 0, n-1);
    }
    SegTree(int n_, T val) : n(n_) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        vector<T> a(n, val);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(int l, int r)        { _update(1, 0, n-1, l,   r  ); }
    void update(int pos)             { _update(1, 0, n-1, pos, pos); }
    T query(int l, int r)            { return _query(1, 0, n-1, l,   r);   }
    T get(int pos)                   { return _query(1, 0, n-1, pos, pos); }
    T operator[](int pos)            { return get(pos); }
};
 
int tt = 1, n, m;
 
void solve() {
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
