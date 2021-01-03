#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 1000;

int t, n, a[MAXN], mp[128];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 0, r = 0, d = INT_MAX, st = 0;
    // Initialize map
    while (r < n) {
        if (mp[a[r++]]-- > 0) {
            // Modify counter
        }
        while ( 0 /* valid */ ) {
            // Update d if finding minimum
            if (mp[a[l++]]++ == 0) {
                // Modify counter
            }
        }
        // Update d if finding maximum
    }
    cout << d << "\n";
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
