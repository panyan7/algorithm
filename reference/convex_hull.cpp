/**
 *  Reference solution using convex hull trick
 *  15-451 Fall 2021 Homework 7 Programming "Farthest Pair"
 *  https://www.cs.cmu.edu/~15451-f21/hws/hw7.pdf
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define pt  array<double,2>

// Convex hull using Graham scan
// Should not contain dulicate points
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

double d2(pt x, pt y) {
    return (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]);
}

void solve() {
    cin >> n;
    vector<pt> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1];
    vector<pt> b = convex_hull(a);
    m = b.size();
    int j = 0;
    double res = 0.0;
    for (int i = 0; i < m; i++) {
        while (d2(b[i],b[j]) < d2(b[i],b[(j+1)%n])) {
            j++;
            j %= n;
        }
        res = max(res, d2(b[i], b[j]));
    }
    cout << fixed << setprecision(10) << sqrt(res) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
