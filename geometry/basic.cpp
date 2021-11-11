#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define pt  complex<double>

pt add(pt a, pt b)                  { return a + b; }
pt mult(pt a, double r)             { return r * a; }
double dot(pt a, pt b)              { return (conj(a) * b).real(); }
double cross(pt a, pt b)            { return (conj(a) * b).imag(); }
double squared_dist(pt a, pt b)     { return norm(a - b); }
double dist(pt a, pt b)             { return abs(a - b); }
double angle(pt a, pt b)            { return arg(b - a); }
double slope(pt a, pt b)            { return tan(arg(b - a)); }
pt po_to_cart(pt p)                 { return polar(p.real(), p.imag()); }
pt cart_to_po(pt a)                 { return pt(abs(a), arg(a)); }
pt rotate(pt a, double theta)       { return a * polar(1.0, theta); }
pt rotate(pt a, pt p, double theta) { return (a-p) * polar(1.0, theta) + p; }
pt project(pt p, pt v)              { return v * dot(p, v) / norm(v); }
pt project(pt p, pt a, pt b)        { return a + project(p-a, b-a); }
pt reflect(pt p, pt a, pt b)        { return a + conj((p-a) / (b-a)) * (b-a); }
pt angle(pt a, pt b, pt c) { 
    return abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI));
}
pt intersection(pt a, pt b, pt p, pt q) {
    double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
    return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

int tt = 1, n, m;
void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
