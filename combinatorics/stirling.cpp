#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int MOD = 7340033;
const int ROOT = 5;
const int ROOT_1 = 4404020;
const int ROOT_PW = 1 << 20;

void ntt(vector<ll>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? ROOT_1 : ROOT;
        for (int i = len; i < ROOT_PW; i <<= 1)
            wlen = (1LL * wlen * wlen % MOD);

        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (1LL * a[i+j+len/2] * w % MOD);
                a[i+j] = u + v < MOD ? u + v : u + v - MOD;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (1LL * w * wlen % MOD);
            }
        }
    }

    if (invert) {
        ll n_1 = inverse(n, MOD);
        for (ll& x : a)
            x = (1LL * x * n_1 % MOD);
    }
}
vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) 
        N <<= 1;
    fa.resize(N);
    fb.resize(N);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] = (fa[i] * fb[i]) % MOD;
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
    while (tt--) {
        solve();
    }
    return 0;
}
