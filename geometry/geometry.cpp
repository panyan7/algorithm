#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const double EPS = 1e-9;
struct Point {
    double x, y;
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
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
    Point& operator+=(const Point& a) {
        x += a.x;
        y += a.y;
        return *this;
    }
    Point& operator-=(const Point& a) {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    Point& operator*=(const double c) {
        x *= c;
        y *= c;
        return *this;
    }
    Point& operator/=(const double c) {
        x /= c;
        y /= c;
        return *this;
    }
    friend Point operator+(const Point& a, const Point& b) {
        return Point(a) += b;
    }
    friend Point operator-(const Point& a, const Point& b) {
        return Point(a) -= b;
    }
    friend Point operator*(const Point& a, const double c) {
        return Point(a) *= c;
    }
    friend Point operator*(const double c, const Point& a) {
        return Point(a) *= c;
    }
    friend Point operator/(const Point& a, const double c) {
        return Point(a) /= c;
    }
    friend double dot(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }
    friend double cross(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }
    friend double len(Point a) {
        double s = a.x * a.x + a.y * a.y;
        return sqrt(s);
    }
    friend double dist(Point a, Point b) {
        return len(a - b);
    }
    friend Point intersect(Point a1, Point d1, Point a2, Point d2) {
        // intersection between a1 + td1 and a2 + td2
        assert(d1 != d2);
        return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
    }
    friend double polygon_area(const vector<Point>& fig) {
        double res = 0;
        for (int i = 0; i < (int)fig.size(); i++) {
            Point p = i ? fig[i - 1] : fig.back();
            Point q = fig[i];
            res += (p.x - q.x) * (p.y + q.y);
        }
        return fabs(res) / 2;
    }
    friend Point proj(Point a, Point b) {
        return b * dot(a, b) / dot(b, b);
    }
    friend double dist_to_line(Point a, Point b, Point c) {
        // distance to line bc
        assert(b != c);
        Point ba = a-b;
        Point bc = c-b;
        Point proj_ba_bc = proj(ba, bc);
        Point rem = ba - proj_ba_bc;
        return len(rem);
    }
    friend bool cw(Point a, Point b, Point c) {
        // clock-wise
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
    }
    friend bool ccw(Point a, Point b, Point c) {
        // counter clock-wise
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
    }
    friend vector<Point> convex_hull(vector<Point>& a) {
        // Convex hull
        if (a.size() == 1)
            return {};
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        Point p1 = a[0], p2 = a.back();
        vector<Point> u, d;
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
        vector<Point> res;
        for (int i = 0; i < (int)u.size(); i++)
            res.push_back(u[i]);
        for (int i = d.size() - 2; i > 0; i--)
            res.push_back(d[i]);
        return res;
    }
};
struct Line {
    double a, b, c;
    Line() : a(0.0), b(0.0), c(0.0) {}
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
    friend ostream& operator<<(ostream& os, const Line& l) {
        return os << l.a << " " << l.b << " " << l.c;
    }
    friend Line offset(Line l, Point a, bool invert=false) {
        // invert = false then (0,0) -> a, true then a -> (0,0)
        if (invert)
            l.c += l.a * a.x + l.b * a.y;
        else
            l.c -= l.a * a.x + l.b * a.y;
        return l;
    }
};
struct Circle {
    Point c;
    double r;
    Circle() : r(0.0) {}
    Circle(double r) : r(r) {}
    Circle(Point c, double r) : c(c), r(r) {}
    friend ostream& operator<<(ostream& os, const Circle& a) {
        return os << a.c << " " << a.r;
    }
    friend istream& operator>>(istream& is, Circle& a) {
        return is >> a.c >> a.r;
    }
    void line_circle_intersection(Circle a, Line l, vector<Point>& ans) {
        l = offset(l, a.c, true);
    }
    void tangent_circle(Circle a, Circle b, vector<Line>& ans) {
        auto tangent_line = [&](Point c, double r1, double r2) {
            double r = r2 - r1;
            double z = c.x * c.x + c.y * c.y;
            double d = z - r * r;
            if (d < -EPS) return;
            d = sqrt(abs(d));
            Line l;
            l.a = (c.x * r + c.y * d) / z;
            l.b = (c.y * r - c.x * d) / z;
            l.c = r1; 
            l = offset(l, a.c);
            ans.push_back(l);
        };
        for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 1; j += 2)
                tangent_line(b.c - a.c, a.r * i, b.r * j);
    }
};
using pt = Point;
int tt = 1, n, m, k;

void solve() {
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
