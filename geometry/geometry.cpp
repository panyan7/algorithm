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
};
struct line {
    double a, b, c;
    line() : a(0.0), b(0.0), c(0.0) {}
    friend ostream& operator<<(ostream& os, const line& l) {
        return os << l.a << " " << l.b << " " << l.c;
    }
};
double dot(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}
double cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}
double len(pt a) {
    double s = a.x * a.x + a.y * a.y;
    return sqrt(s);
}
double dist(pt a, pt b) {
    return len(a - b);
}
pt intersect(pt a1, pt d1, pt a2, pt d2) {
    // intersection between a1 + td1 and a2 + td2
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
vector<line> tangent_circle(circle a, circle b) {
    vector<line> ans;
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
        ans.push_back(l);
    };
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2)
            tangent_line(b.c - a.c, a.r * i, b.r * j);
    for (int i = 0; i < (int)ans.size(); i++)
        ans[i].c -= ans[i].a * a.c.x + ans[i].b * a.c.y;
    return ans;
}

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
