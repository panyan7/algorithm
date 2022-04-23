#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const double EPS = 1e-9;

struct pt {
    double x, y;
    pt() : x(0.0), y(0.0) {}
    pt(double x, double y) : x(x), y(y) {}
    friend ostream& operator<<(ostream& os, const pt& a) {
        return os << "(" << a.x << "," << a.y << ")";
    }
    friend istream& operator>>(istream& is, pt& a) {
        return is >> a.x >> a.y;
    }
    friend bool operator==(const pt& a, const pt& b) {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator!=(const pt& a, const pt& b) {
        return !(a == b);
    }
    friend bool operator<(const pt& a, const pt& b) {
        return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
    }
    pt& operator+=(const pt& a) {
        x += a.x;
        y += a.y;
        return *this;
    }
    pt& operator-=(const pt& a) {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    pt& operator*=(const double c) {
        x *= c;
        y *= c;
        return *this;
    }
    pt& operator/=(const double c) {
        x /= c;
        y /= c;
        return *this;
    }
    friend pt operator+(const pt& a, const pt& b) {
        return pt(a) += b;
    }
    friend pt operator-(const pt& a, const pt& b) {
        return pt(a) -= b;
    }
    friend pt operator*(const pt& a, const double c) {
        return pt(a) *= c;
    }
    friend pt operator*(const double c, const pt& a) {
        return pt(a) *= c;
    }
    friend pt operator/(const pt& a, const double c) {
        return pt(a) /= c;
    }
    friend double dot(pt a, pt b) {
        return a.x * b.x + a.y * b.y;
    }
    friend double cross(pt a, pt b) {
        return a.x * b.y - a.y * b.x;
    }
    friend double len(pt a) {
        double s = a.x * a.x + a.y * a.y;
        return sqrt(s);
    }
    friend double dist(pt a, pt b) {
        return len(a - b);
    }
    friend pt intersect(pt a1, pt d1, pt a2, pt d2) {
        // intersection between a1 + td1 and a2 + td2
        assert(d1 != d2);
        return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
    }
    friend double polygon_area(const vector<pt>& fig) {
        double res = 0;
        for (int i = 0; i < (int)fig.size(); i++) {
            pt p = i ? fig[i - 1] : fig.back();
            pt q = fig[i];
            res += (p.x - q.x) * (p.y + q.y);
        }
        return fabs(res) / 2;
    }
    friend pt proj(pt a, pt b) {
        return b * dot(a, b) / dot(b, b);
    }
    friend double dist_to_line(pt a, pt b, pt c) {
        // distance to line bc
        assert(b != c);
        pt ba = a-b;
        pt bc = c-b;
        pt proj_ba_bc = proj(ba, bc);
        pt rem = ba - proj_ba_bc;
        return len(rem);
    }
    friend bool cw(pt a, pt b, pt c) {
        // clock-wise
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
    }
    friend bool ccw(pt a, pt b, pt c) {
        // counter clock-wise
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
    }
    friend vector<pt> convex_hull(vector<pt>& a) {
        // Convex hull
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
};
struct line {
    double a, b, c;
    line() : a(0.0), b(0.0), c(0.0) {}
    line(double a, double b, double c) : a(a), b(b), c(c) {}
    friend ostream& operator<<(ostream& os, const line& l) {
        return os << l.a << " " << l.b << " " << l.c;
    }
    friend line offset(line l, pt a, bool invert=false) {
        // invert = false then (0,0) -> a, true then a -> (0,0)
        if (invert)
            l.c += l.a * a.x + l.b * a.y;
        else
            l.c -= l.a * a.x + l.b * a.y;
        return l;
    }
};
struct circle {
    pt c;
    double r;
    circle() : r(0.0) {}
    circle(double r) : r(r) {}
    circle(pt c, double r) : c(c), r(r) {}
    friend ostream& operator<<(ostream& os, const circle& a) {
        return os << a.c << " " << a.r;
    }
    friend istream& operator>>(istream& is, circle& a) {
        return is >> a.c >> a.r;
    }
    void line_circle_intersection(circle a, line l, vector<pt>& ans) {
        l = offset(l, a.c, true);
    }
    void tangent_circle(circle a, circle b, vector<line>& ans) {
        auto tangent_line = [&](pt c, double r1, double r2) {
            double r = r2 - r1;
            double z = c.x * c.x + c.y * c.y;
            double d = z - r * r;
            if (d < -EPS) return;
            d = sqrt(abs(d));
            line l;
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
