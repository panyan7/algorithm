#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()
#define F_OR1(n) for (int i = 0; i < n; ++i)
#define F_OR2(i, n) for (int i = 0; i < n; ++i)
#define F_OR3(i, k, n) for (int i = k; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define F_OR(...) GET_MACRO(__VA_ARGS__, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_OR(__VA_ARGS__) (__VA_ARGS__)
#define EACH(x, a) for (auto& x : a)
const int MOD = 1e9+7;

struct frac {
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
    frac () : m(0), n(1) {}
    frac (int64_t a) : m(a), n(1) {}
    frac (int64_t a, int64_t b) {
        assert(b > 0);
        m = a, n = b;
        upd(m, n);
    }
    explicit operator int () const { return int(m / n); }
    explicit operator int64_t () const { return m / n; }
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
    frac inv() const { 
        assert(m != 0);
        return m < 0 ? frac(-n, -m) : frac(n, m);
    }
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
    friend frac pow(const frac& a, int e) {
        if (e < 0) return pow(a, -e).inv();
        frac res = 1, b = a;
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

int t;

void solve() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
