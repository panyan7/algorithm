#include <bits/stdc++.h>
using namespace std;
typedef long long int64_t;

struct frac {
    int64_t m, n;
    frac () : m(0), n(1) {}
private:
    static int64_t gcd(int64_t a, int64_t b) {
        if (a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    static void upd(int64_t& a, int64_t& b) {
        int64_t g = a ? gcd(a, b) : b;
        a /= g, b /= g;
    }
public:
    frac (int64_t a, int64_t b) {
        assert(b != 0);
        m = a, n = b;
        upd(m, n);
    }
    explicit operator double () const { return double(m) / double(n); }
    friend ostream& operator << (ostream& os, const frac& x) {
        if (x.m == 0) return os << 0;
        if (x.n == 1) return os << x.m;
        return os << x.m << "/" << x.n;
    }
    friend istream& operator >> (istream& is, frac& x) {
        return is >> x.m >> x.n;
    }
    friend bool operator == (const frac& a, const frac& b) {
        return a.m == b.m && a.n == b.n;
    }
    friend bool operator != (const frac& a, const frac& b) {
        return !(a == b);
    }
    frac neg() const { return frac(-m, n); }
    frac inv() const { assert(m != 0); return frac(n, m); }
    frac& operator ++ () { m += n; return *this; }
    frac& operator -- () { m -= n; return *this; }
    frac& operator += (const frac& o) {
        int64_t g = gcd(n, o.n);
        m = m * (o.n / g) + o.m * (n / g);
        n *= (o.n / g);
        upd(m, n);
        return *this;
    }
    frac& operator -= (const frac& o) {
        return *this += o.neg();
    }
    frac& operator *= (const frac& o) {
        m *= o.m, n *= o.n;
        upd(m, n);
        return *this;
    }
    frac& operator /= (const frac& o) {
        return *this *= o.inv();
    }
    friend frac operator + (const frac& a, const frac& b) {
        return frac(a) += b;
    }
    friend frac operator - (const frac& a, const frac& b) {
        return frac(a) -= b;
    }
    friend frac operator * (const frac& a, const frac& b) {
        return frac(a) *= b;
    }
    friend frac operator / (const frac& a, const frac& b) {
        return frac(a) /= b;
    }
};

int main() {
    frac a (1, 2), b (2, 3), c (0, 1), d (2, 4), e (6, 3);
    cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
    cout << a + b << a * b << a / b;
}
