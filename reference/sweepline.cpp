/**
 *  Reference solution using sweepline technique
 *  Codeforces 1420 D "Rescue Nibel!"
 *  https://codeforces.com/contest/1420/problem/D
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

// const int MOD = 1e9+7;
const int MOD = 998244353;
using num = ModNum<MOD>;
num fact[300005];
int tt = 1, n, m;

num choose(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] / fact[n-k] / fact[k];
}

void solve() {
    int k;
    cin >> n >> k;
    vector<pll> a(n);
    for (auto& x : a)
        cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    // sweep line
    num res = 0;
    int num_old = 0, num_new = 0;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first < a[i].first) {
            pq.pop();
            num_old--;
        }
        pq.push({a[i].second, i});
        num_new++;
        if (i+1 < n && a[i+1].first == a[i].first)
            continue;
        //cout << num_old << "/" << num_new << " ";
        res += (choose(num_old + num_new, k) - choose(num_old, k));
        num_old += num_new;
        num_new = 0;
        //cout << res << " ";
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    fact[0] = 1;
    for (int i = 1; i <= 300000; i++)
        fact[i] = fact[i-1] * i;
    while (tt--)
        solve();
    return 0;
}
