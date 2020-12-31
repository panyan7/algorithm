#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int n, t[4*MAXN], a[MAXN];

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

