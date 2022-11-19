#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define pt  array<double,2>

// Convex hull using monotone chain
template <typename T>
struct Point {
    T x, y;
    Point() : x(0.0), y(0.0) {}
    Point(T x, T y) : x(x), y(y) {}
    Point(vector<T>& a) : x(a[0]), y(a[1]) {}
    friend ostream& operator<<(ostream& os, const Point& a) {
        return os << "(" << a.x << "," << a.y << ")";
    }
    friend istream& operator>>(istream& is, Point& a) {
        return is >> a.x >> a.y;
    }
    friend bool operator==(const Point& a, const Point& b) {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator!=(const Point& a, const Point& b) {
        return !(a == b);
    }
    friend bool operator<(const Point& a, const Point& b) {
        return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
    }
    friend int orientation(Point a, Point b, Point c) {
        T v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
        if (v < 0) return -1; // clockwise
        if (v > 0) return +1; // counter-clockwise
        return 0;
    }
    friend bool cw(Point a, Point b, Point c, bool include_collinear=false) {
        int o = orientation(a, b, c);
        return o < 0 || (include_collinear && o == 0);
    }
    friend bool ccw(Point a, Point b, Point c, bool include_collinear=false) {
        int o = orientation(a, b, c);
        return o > 0 || (include_collinear && o == 0);
    }
    friend bool collinear(Point a, Point b, Point c) {
        return orientation(a, b, c) == 0;
    }
    friend vector<Point> convex_hull(vector<Point>& a, bool include_collinear=false) {
        // Convex hull
        if (a.size() == 1)
            return a;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        Point p1 = a[0], p2 = a.back();
        vector<Point> u, d;
        u.push_back(p1);
        d.push_back(p1);
        for (int i = 1; i < (int)a.size(); i++) {
            if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
                while (u.size() >= 2
                        && !cw(u[u.size()-2], u[u.size()-1], a[i], include_collinear))
                    u.pop_back();
                u.push_back(a[i]);
            }
            if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
                while (d.size() >= 2
                        && !ccw(d[d.size()-2], d[d.size()-1], a[i], include_collinear))
                    d.pop_back();
                d.push_back(a[i]);
            }
        }
        if (include_collinear && a.size() == u.size()) {
            vector<Point> res = a;
            reverse(res.begin(), res.end());
            return res;
        }
        vector<Point> res;
        for (int i = 0; i < (int)u.size(); i++)
            res.push_back(u[i]);
        for (int i = d.size() - 2; i > 0; i--)
            res.push_back(d[i]);
        return res;
    }
};

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
