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


template <int MOD>
struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(int64_t v_) : v(int(v_ % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator << (ostream& os, const modnum& m) {
        return os << int(m);
    }
    friend istream& operator >> (istream& is, modnum& m) {
        return is >> m.v;
    }
    modnum& operator ++ () {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum operator ++ (int) {
        modnum r = *this;
        ++*this;
        return r;
    }
    modnum& operator -- () {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum operator -- (int) {
        modnum r = *this;
        --*this;
        return r;
    }
    modnum neg() const {
        modnum r = *this;
        if (v == 0) r.v = MOD;
        else r.v = MOD - v;
        return r;
    }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    modnum inv() const { assert(v); return modnum(minv(v, MOD)); }
    modnum& operator += (const modnum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }
    friend modnum operator + (const modnum& a, const modnum& b) {
        return modnum(a) += b;
    }
    friend modnum operator - (const modnum& a, const modnum& b) {
        return modnum(a) -= b;
    }
    friend modnum operator * (const modnum& a, const modnum& b) {
        return modnum(a) *= b;
    }
    friend modnum operator / (const modnum& a, const modnum& b) {
        return modnum(a) /= b;
    }
    friend modnum pow(const modnum& a, int e) {
        modnum res = 1;
        while (e) {
            if (e % 2) res *= a;
            e /= 2;
            a *= a;
        }
        return res;
    }
};

typedef modnum<MOD> num;
int t;

void solve() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
