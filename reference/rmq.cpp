/*
    Reference Solution using Range Minimun Query
    Codeforces 1473 D "Program"
    https://codeforces.com/contest/1473/problem/D
*/
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
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr (n+1, 0);
    for (int i = 1; i <= n; ++i)
        arr[i] = arr[i-1] + (s[i-1] == '+' ? 1 : -1);
    RMQ mn (arr), mx (arr, true);
    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        int mn1 = mn.query(0,l-1);
        int mx1 = mx.query(0,l-1);
        if (r == n) {
            cout << (mx1-mn1+1) << "\n";
            continue;
        }
        int mn2 = mn.query(r+1,n)-arr[r]+arr[l-1];
        int mx2 = mx.query(r+1,n)-arr[r]+arr[l-1];
        cout << (max(mx2,mx1)-min(mn2,mn1)+1) << "\n";
    }
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
