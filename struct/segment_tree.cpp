#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int n;
vector<int> x;

template<typename T>
struct segtree {
    int n;
    vector<T> t, a;
private:
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int m = tl + (tr-tl)/2;
            build(v*2, tl, m);
            build(v*2+1, m+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
public:
    segtree (vector<T>& b) {
        a = b;
        int n = a.size();
        t = vector<T> (4*n);
        build(1, 0, n-1);
    }
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        int m = tl + (tr-tl)/2;
        return sum(v*2, tl, m, l, min(r, m)) 
             + sum(v*2+1, m+1, tr, max(l, m+1), r);
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int m = tl + (tr-tl)/2;
            if (pos <= m) update(v*2, tl, m, pos, val);
            else update(v*2+1, m+1, tr, pos, val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};

