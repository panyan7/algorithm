#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

struct Fraction {
    int64_t m, n;
private:
    static int64_t gcd(int64_t a, int64_t b) {
        if (a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    static void upd(int64_t& a, int64_t& b) {
        int64_t g = a ? gcd(abs(a), b) : b;
        a /= g, b /= g;
    }
public:
    Fraction() : m(0), n(1) {}
    Fraction(int64_t a) : m(a), n(1) {}
    Fraction(int64_t a, int64_t b) {
        assert(b > 0);
        m = a, n = b;
        upd(m, n);
    }
    explicit operator int () const { return int(m / n); }
    explicit operator int64_t () const { return m / n; }
    explicit operator double () const { return double(m) / double(n); }
    friend ostream& operator<<(ostream& os, const Fraction& x) {
        if (x.m == 0) return os << 0;
        if (x.n == 1) return os << x.m;
        return os << x.m << "/" << x.n;
    }
    friend istream& operator>>(istream& is, Fraction& x) {
        return is >> x.m >> x.n;
    }
    friend bool operator==(const Fraction& a, const Fraction& b) {
        return a.m == b.m && a.n == b.n;
    }
    friend bool operator!=(const Fraction& a, const Fraction& b) {
        return !(a == b);
    }
    Fraction neg() const { return Fraction(-m, n); }
    Fraction inv() const { 
        assert(m != 0);
        return m < 0 ? Fraction(-n, -m) : Fraction(n, m);
    }
    Fraction& operator++() { m += n; return *this; }
    Fraction& operator--() { m -= n; return *this; }
    Fraction& operator+=(const Fraction& o) {
        int64_t g = gcd(n, o.n);
        m = m * (o.n / g) + o.m * (n / g);
        n *= (o.n / g);
        upd(m, n);
        return *this;
    }
    Fraction& operator-=(const Fraction& o) { return *this += o.neg(); }
    Fraction& operator*=(const Fraction& o) {
        m *= o.m, n *= o.n;
        upd(m, n);
        return *this;
    }
    Fraction& operator/=(const Fraction& o) {
        return *this *= o.inv();
    }
    friend Fraction operator+(const Fraction& a, const Fraction& b) {
        return Fraction(a) += b;
    }
    friend Fraction operator-(const Fraction& a, const Fraction& b) {
        return Fraction(a) -= b;
    }
    friend Fraction operator*(const Fraction& a, const Fraction& b) {
        return Fraction(a) *= b;
    }
    friend Fraction operator/(const Fraction& a, const Fraction& b) {
        return Fraction(a) /= b;
    }
    friend Fraction pow(const Fraction& a, int e) {
        if (e < 0) return pow(a, -e).inv();
        Fraction res = 1, b = a;
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

int t = 1, n, m, k, q;

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
