#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

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
template <class B>
struct SegTree : public B {
    using T = typename B::T;
    int n, m;
    vector<vector<T>> tree;
private:
    void _build_y(const vector<vector<T>>& a, int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                tree[vx][vy] = a[lx][ly];
            else
                tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];
        } else {
            int my = (ly + ry) / 2;
            _build_y(a, vx, lx, rx, vy*2, ly, my);
            _build_y(a, vx, lx, rx, vy*2+1, my+1, ry);
            tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
        }
    }
    void _build_x(const vector<vector<T>>& a, int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(a, vx*2, lx, mx);
            build_x(a, vx*2+1, mx+1, rx);
        }
        _build_y(a, vx, lx, rx, 1, 0, m-1);
    }
    T _query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) 
            return 0;
        if (ly == tly && try_ == ry)
            return tree[vx][vy];
        int tmy = (tly + try_) / 2;
        return B::f(_query_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)),
                    _query_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
    }
    T _query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx)
            return 0;
        if (lx == tlx && trx == rx)
            return _query_y(vx, 1, 0, m-1, ly, ry);
        int tmx = (tlx + trx) / 2;
        return B::f(_query_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry),
                    _query_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
    }
    void _update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
        if (ly == ry) {
            if (lx == rx)
                tree[vx][vy] = new_val;
            else
                tree[vx][vy] = B::f(tree[vx*2][vy], tree[vx*2+1][vy]);
        } else {
            int my = (ly + ry) / 2;
            if (y <= my)
                _update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
            else
                _update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
            tree[vx][vy] = B::f(tree[vx][vy*2], tree[vx][vy*2+1]);
        }
    }
    void _update_x(int vx, int lx, int rx, int x, int y, int new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                _update_x(vx*2, lx, mx, x, y, new_val);
            else
                _update_x(vx*2+1, mx+1, rx, x, y, new_val);
        }
        _update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
    }
public:
    SegTree(int n_, int m_) : n(n_), m(m_) {
        tree.assign(4*n, vector<T>(4*m, B::e));
        vector<T> a(n, vector<T>(m, B::e));
        _build_y(a, 1, 0, n-1, 1, 0, m-1);
    }
    SegTree(const vector<vector<T>>& a) : n(a.size()), m(a[0].size()) {
        tree.assign(4*n, vector<T>(4*m, B::e));
        _build_y(a, 1, 0, n-1, 1, 0, m-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)              { _build(a, 1, 0, n-1); }
    void update(T val, int x, int y)            { _update_x(1, 0, n-1, x, y, val); }
    T query(int lx, int rx, int ly, int ry)     { return _query_x(1, 0, n-1, lx, rx, ly, ry); }
};


int tt = 1, n, m, k;

// check long long
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
