#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        // use lower_bound for increasing, upper_bound for non-decreasing
        auto it = lower_bound(d.begin(), d.end(), a[i]); // increasing
        // auto it = upper_bound(d.begin(), d.end(), a[i]); // non-decreasing
        if (it != d.end())
            *it = a[i];
        else
            d.push_back(a[i]);
    }
    // result is d.size()
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
