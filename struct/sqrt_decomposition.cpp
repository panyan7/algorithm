#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct Sqrt {
    int n, len;
    vector<ll> a;
    vector<ll> b;
private:
    void init() {
        len = (int)sqrt((double)n) + 1;
        b.assign(len, 0);
        for (int i = 0; i < n; i++)
            b[i / len] += a[i];
    }
public:
    Sqrt(vector<ll>& a_) {
        a = a_;
        n = a.size();
        init();
    }
    int query(int l, int r) {
        ll sum = 0;
        for (int i = l; i <= r; ) {
            if (i % len == 0 && i + len - 1 <= r) {
                sum += b[i / len];
                i += len;
            } else {
                sum += a[i];
                i++;
            }
        }
        return sum;
    }
};

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
