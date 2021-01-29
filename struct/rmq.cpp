#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

struct RMQ {
    vector<vector<int>> spt;
    int size, maxk;
    bool rev;
private:
    void build (const vector<int>& a) {
        size = a.size();
        maxk = floor(log2(size)+1);
        spt = vector<vector<int>> (maxk+1, vector<int> (size, 0));
        for (int i = 0; i < size; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= maxk; ++k) {
            for (int i = 0; i <= size-(1<<k); ++i) {
                if (!rev) spt[k][i] = min(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
                else      spt[k][i] = max(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
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
        if (!rev) return min(spt[k][i], spt[k][j-(1<<k)+1]);
        else      return max(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

int t, n, m;

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
