#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    vector<vector<int>> spt;
    int n, maxk;
    bool rev;
private:
    void build (const vector<int>& a) {
        n = a.size();
        maxk = floor(log2(n)+1);
        spt = vector<vector<int>> (n, vector<int> (maxk+1, 0));
        for (int i = 0; i < n; ++i) {
            spt[0][i] = a[i];
        }
        for (int k = 1; k <= maxk; ++k) {
            for (int i = 0; i < n-(1<<k); ++i) {
                if (!rev) spt[k][i] = min(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
                else spt[k][i] = max(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
            }
        }
    }
public:
    RMQ (const vector<int>& a) : rev(false) {
        build(a);
    }
    RMQ (const vector<int>& a, bool r) : rev(r) {
        build(a);
    }
    int query(const int i, const int j) {
        int k = floor(log2(j-i+1));
        if (!rev) return min(spt[k][i], spt[k][j-(i<<k)+1]);
        else return max(spt[k][i], spt[k][j-(i<<k)+1]);
    }
};
