#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t, int64_t>

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
    friend ostream& operator << (ostream& os, SegTree st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void update(int val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(int val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T sum(int l, int r) { return _sum(1, 0, n-1, l, r); }
    T get(int pos)      { return _get(1, 0, n-1, pos);  }
};

int t = 1, n;

void solve() {
}

void test() {
    vector<int> a ({1, 2, 3, 4, 5, 6, 7, 8});
    SegTree<int> sg (a);
    sg.update(3, 0, 4);
    cout << sg;
    sg.update(1, 3, 5);
    cout << sg;
    int n = sg.n;
    for (int i = 0; i < n; ++i) {
        cout << sg.get(i) << " ";
        for (int j = i; j < n; ++j) {
            cout << sg.sum(i, j) << " ";
        }
        cout << "\n";
    }
    sg.update(6, 6, 7);
    sg.update(0, 1);
    sg.update(2, 7);
    cout << sg;
    for (int i = 0; i < n; ++i) {
        cout << sg.get(i) << " ";
        for (int j = i; j < n; ++j) {
            cout << sg.sum(i, j) << " ";
        }
        cout << "\n";
    }
    cout << "FINISHED\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    test();
    /*cin >> t;
    while (t--) {
        solve();
    }*/
    return 0;
}
