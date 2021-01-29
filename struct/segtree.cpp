#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t, int64_t>

/* Segment tree with range assignment query and range sum query */
template<typename T>
struct SegTree {
    int n;
    vector<T> tree;
    vector<bool> mark;
    SegTree (vector<T>& a) : n(a.size()) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        build(a, 1, 0, n-1);
    }
private:
    void build(vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            mark[v] = true;
        } else {
            int tmid = tl + (tr - tl) / 2;
            build(a, v*2, tl, tmid);
            build(a, v*2+1, tmid+1, tr);
            tree[v] = 0;
        }
    }
    void push(int v) {
        if (mark[v]) {
            tree[v*2] = tree[v*2+1] = tree[v];
            mark[v*2] = mark[v*2+1] = true;
            mark[v] = false;
        }
    }
    void _update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] = val;
            mark[v] = true;
            return;
        }
        push(v);
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
    }
    T _query(int v, int tl, int tr, int l, int r) {
        if (l > r || tr < l || tl > r)
            return 0;
        if (mark[v] && tr >= r && tl <= l)
            return tree[v] * (r-l+1);
        int tmid = tl + (tr - tl) / 2;
        return _query(v*2, tl, tmid, l, min(r, tmid)) +
               _query(v*2+1, tmid+1, tr, max(l, tmid+1), r);
    }
    T _get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return tree[v];
        if (mark[v]) {
            // push(v); /* Optional */
            return tree[v];
        }
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    friend ostream& operator << (ostream& os, SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void update(T val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T query(int l, int r) { return _query(1, 0, n-1, l, r); }
    T get(int pos)      { return _get(1, 0, n-1, pos);  }
    T operator [] (int pos) { return get(pos); }
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
