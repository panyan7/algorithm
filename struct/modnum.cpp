#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <int MOD>
struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(int64_t v_) : v(int(v_ % MOD)) {}

    explicit operator int() const {
        return v;
    }

    friend ostream& operator << (ostream& o, const modnum& m) {
        return o << int(m);
    }
    friend istream& operator >> (istream& i, const modnum& m) {
        int64_t val;
        i >> val;
        m = modnum(val);
        return i;
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
    modnum inv() const {}

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
};

int main() {
    typedef modnum<(int)1e9+7> num;
    num x = (int)1e9;
    num y = 8;
    cout << ++x << " " << (x + y) << endl;
    return 0;
}
