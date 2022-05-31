#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

struct MaxSumInt {
    ll INF = 1e14;
    ll prefix_sum, suffix_sum, total_sum, subarray_sum;
    MaxSumInt() {
        prefix_sum = -INF;
        suffix_sum = -INF;
        total_sum = 0;
        subarray_sum = -INF; 
    }
    MaxSumInt(ll prefix_sum_, ll suffix_sum_, ll total_sum_, ll subarray_sum_) {
        prefix_sum = prefix_sum_;
        suffix_sum = suffix_sum_;
        total_sum = total_sum_;
        subarray_sum = subarray_sum_;
    }
};
struct MaxSum {
    using T = MaxSumInt;
    const T e = MaxSumInt();
    T f(T a, T b) const {
        ll prefix_sum = max(a.prefix_sum, a.total_sum + b.prefix_sum);
        ll suffix_sum = max(b.suffix_sum, b.total_sum + a.suffix_sum);
        ll total_sum = a.total_sum + b.total_sum;
        ll subarray_sum = max({a.subarray_sum, b.subarray_sum, a.suffix_sum + b.prefix_sum});
        return MaxSumInt(prefix_sum, suffix_sum, total_sum, subarray_sum);
    }
};
template <class B>
struct SegTree : public B {
    using T = typename B::T;
    int n;
    vector<T> tree;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    void _update(int v, int tl, int tr, int pos, T val) {
        if (tl > tr || pos > tr || pos < tl)
            return;
        if (pos == tl && pos == tr) {
            tree[v] = val;
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, pos, val);
        _update(v*2+1, tmid+1, tr, pos, val);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    T _query(int v, int tl, int tr, int l, int r) const {
        if (l > r || tr < l || tl > r)
            return B::e;
        if (tr <= r && tl >= l)
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        return B::f(_query(v*2, tl, tmid, l, min(r, tmid)),
                    _query(v*2+1, tmid+1, tr, max(l, tmid+1), r));
    }
    T _get(int v, int tl, int tr, int pos) const {
        if (tl == tr)
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, B::e);
        vector<T> a(n, B::e);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, B::e);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
};

int tt = 1, n, m, q;

void solve() {
    cin >> n >> q;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector<MaxSumInt> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = MaxSumInt(a[i], a[i], a[i], a[i]);
    }
    SegTree<MaxSum> st(b);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r).subarray_sum << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
