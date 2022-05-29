#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    // finds maximum xor of any two numbers in a
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int mx = 0, mask = 0;
    unordered_set<int> st;
    for (int i = 30; i >= 0; i--) {
        mask |= (1 << i);
        for (int i = 0; i < (int)a.size(); ++i)
            st.insert(a[i] & mask);
        int new_mx = mx | (1 << i);
        for (int prefix : st) {
            if (st.count(new_mx ^ prefix)) {
                mx = new_mx;
                break;
            }
        }
        st.clear();
    }
    // result is mx
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
