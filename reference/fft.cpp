/**
 *  Reference solution using fast Fourier transform (FFT)
 *  Codeforces 827 E "Rusty String"
 *  https://codeforces.com/contest/827/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) 
        N <<= 1;
    fa.resize(N);
    fb.resize(N);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(N);
    for (int i = 0; i < N; i++)
        result[i] = round(fa[i].real());
    return result;
}

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') {
            a[i] = 1;
        }
        if (s[i] == 'K') {
            b[n-1-i] = 1;
        }
    }
    vector<int> c = multiply(a, b);
    vector<int> sieve(n+1, 0);
    for (int i = 0; i < c.size(); i++)
        if (c[i])
            sieve[abs(i-n+1)] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (sieve[j]) {
                sieve[i] = 1;
                break;
            }
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!sieve[i]) {
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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
