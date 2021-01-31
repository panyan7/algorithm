#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define read(a) for (auto& x : a) cin >> x
#define write(a) for (auto& x : a) cout << x << " "; cout << "\n"

template<typename T>
struct RMQ {
    vector<vector<T>> spt;
    int n, lim;
    bool rev;
    RMQ (const vector<T>& a) : rev(false) { _build(a); }
    RMQ (const vector<T>& a, bool reversed) : rev(reversed) { _build(a); }
private:
    void _build (const vector<T>& a) {
        n = a.size();
        lim = floor(log2(n)+1);
        spt = vector<vector<T>> (lim+1, vector<T> (n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k) {
            for (int i = 0; i <= n-(1<<k); ++i) {
                if (!rev) spt[k][i] = min(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
                else      spt[k][i] = max(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
            }
        }
    }
public:
    T query(const int i, const int j) {
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
