#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;
    FenwickTree(int n_) : n(n_) { bit.assign(n, 0); }
    FenwickTree(vector<int>& a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; ++i)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (int i = r; i >= 0; i = (i & (i+1)) - 1)
            ret += bit[i];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    void add(int idx, int delta) {
        for (int i = idx; i < n; i = i | (i + 1))
            bit[i] += delta;
    }
};

int t = 1, n, m, k, q;
