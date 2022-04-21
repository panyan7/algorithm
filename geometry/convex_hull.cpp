#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define pt  array<double,2>

// Convex hull using Graham scan
bool cw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) <= 0;
}
bool ccw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) > 0;
}
vector<pt> convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return {};
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    pt p1 = a[0], p2 = a.back();
    vector<pt> u, d;
    u.push_back(p1);
    d.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (u.size() >= 2 && !cw(u[u.size()-2], u[u.size()-1], a[i]))
                u.pop_back();
            u.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (d.size() >= 2 && !ccw(d[d.size()-2], d[d.size()-1], a[i]))
                d.pop_back();
            d.push_back(a[i]);
        }
    }
    vector<pt> res;
    for (int i = 0; i < (int)u.size(); i++)
        res.push_back(u[i]);
    for (int i = d.size() - 2; i > 0; i--)
        res.push_back(d[i]);
    return res;
}

int tt = 1, n, m;

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
