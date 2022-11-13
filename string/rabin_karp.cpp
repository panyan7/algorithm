#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Rabin-Karp Fingerprinting
template <long long MOD, long long Base = 256LL>
struct RabinKarp {
    int n;
    vector<long long> p, a, a_rev;
private:
    template <class C>
    void init(const C& s) {
        a.resize(n+1);
        p.resize(n+1);
        a_rev.resize(n+1);
        p[0] = 1;
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i-1] * Base) % MOD;
            a[i] = (a[i-1] * Base + s[i-1]) % MOD;
        }
        a_rev[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            a_rev[i] = (a_rev[i+1] * Base + s[i]) % MOD;
        }
    }
public:
    RabinKarp(const string& s) : n(s.size()) { init<string>(s); }
    RabinKarp(const vector<int>& s) : n(s.size()) { init<vector<int>>(s); }
    long long hash(int l, int r) {
        return ((a[r+1] - a[l] * p[r-l+1]) % MOD + MOD) % MOD;
    }
    long long hash_rev(int l, int r) {
        return ((a_rev[l] - a_rev[r+1] * p[r-l+1]) % MOD + MOD) % MOD;
    }
};
const long long MOD = 999998727899999;
constexpr const long long MOD_LIST[] = {
    200147986693,
    243504973489,
    318083817907,
    414507281407
};
/**
 * N should be number of primes to use
 * C should be string or vector<int>
 * F should be decltype(f) for lambda function f
 */
template <size_t I = 0, size_t N, class C, class F>
typename enable_if<(I == N), void>::type
foreachmod(C& a, F& f) { return; }
template <size_t I = 0, size_t N, class C, class F>
typename enable_if<(I < N), void>::type
foreachmod(C& a, F& f) {
    constexpr const long long M = MOD_LIST[I];
    RabinKarp<M> RK(a);
    f(RK);
    foreachmod<I + 1, N, C, F>(a, f);
}

int tt = 1, n, m, k;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
