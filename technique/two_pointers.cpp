#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

int t, n;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && true/* */) {
            r++;
        }
        // do stuff
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
