#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Vanilla Segment Tree
// O(n log n) preprocessing, O(log n) query, O(log n) update
struct SumInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const { return a + b; }
};
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
struct LCMInt {
    using T = long long;
    const T e = 1;
    T _gcd(T a, T b) const {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        return gcd(a, b);
    }
    T f(T a, T b) const {
        assert(a != 0 && b != 0);
        return a * b / gcd(a, b);
    }
};
struct XORInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const { return (a ^ b); }
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
    SegTree(int n_, T val) : n(n_) {
        tree.assign(4*n, B::e);
        vector<T> a(n, val);
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
    void update(int pos, T val)      { _update(1, 0, n-1, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
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
