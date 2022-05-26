#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int((v_ + MOD) % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

const int MOD = 7340033;
// const int MOD = 998244353;
using num = ModNum<MOD>;
const num root = 5;
const num root_1 = 4404020;
const int root_pw = 1 << 20;
int tt = 1, n, m;

void ntt(vector<num>& a, bool invert) {
    assert(n == n);
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        num wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = wlen * wlen;
        for (int i = 0; i < n; i += len) {
            num w = 1;
            for (int j = 0; j < len / 2; j++) {
                num u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w * wlen;
            }
        }
    }
    if (invert) {
        num n_1 = num(n).inv();
        for (num& x : a)
            x = x * n_1;
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<num> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) 
        N <<= 1;
    fa.resize(N);
    fb.resize(N);
    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] = fa[i] * fb[i];
    ntt(fa, true);
    vector<int> result(N);
    for (int i = 0; i < N; i++)
        result[i] = (int)fa[i];
    return result;
}

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
