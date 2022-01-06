/**
 *  Reference solution using inverse sum over subsets dp
 *  Codeforces 1620 G "Subsequences Galore"
 *  https://codeforces.com/contest/1620/problem/G
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int(v_ % MOD)) {}
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

//const int MOD = 1e9+7;
const int MOD = 998244353;
using num = ModNum<MOD>;
int tt = 1, n, m;

template<class T_in, class T_out>
vector<T_out> inverse_sum_over_subsets(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i];
    for (int i = 0; i < n; i++)
        for (int base = 0; base < (1 << n); base += (1 << (i+1)))
            for (int mask = base; mask < base + (1 << i); mask++)
                f[mask + (1 << i)] -= f[mask];
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) % 2 == 0)
            f[mask] = 0-f[mask];
    }
    return f;

}

void solve() {
    cin >> n;
    vector<array<int,26>> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int j = 0;
        array<int,26> cnt = {};
        for (char c : s)
            cnt[c-'a']++;
        a.push_back(cnt);
    }
    vector<num> b(1 << n, 0);
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> mins(26, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int c = 0; c < 26; c++) {
                    mins[c] = min(mins[c], a[i][c]);
                }
            }
        }
        b[mask] = 1;
        for (int c = 0; c < 26; c++) {
            b[mask] *= num(mins[c] + 1);
        }
    }

    vector<num> f = inverse_sum_over_subsets<num, num>(b);

    ll ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int k = __builtin_popcount(mask), sm = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                sm += (i+1);
        ans ^= (ll)f[mask].v * k * sm;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}
