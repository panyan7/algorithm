#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

int max_xor(vector<int>& a) {
    int maxx = 0, mask = 0;
    unordered_set<int> se;
    for (int i = 30; i >= 0; i--) {
        mask |= (1 << i);
        for (int i = 0; i < (int)a.size(); ++i)
            se.insert(a[i] & mask);
        int new_maxx = maxx | (1 << i);
        for (int prefix : se) {
            if (se.count(new_maxx ^ prefix)) {
                maxx = new_maxx;
                break;
            }
        }
        se.clear();
    }
    return maxx;
}

// check long long
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