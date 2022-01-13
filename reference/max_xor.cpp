/**
 *  Reference solution using calculation of maximum pairwise xor in array
 *  Codeforces 1625 D "Binary Spiders"
 *  https://codeforces.com/contest/1625/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<int> a;

// check long long
void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto& x : a)
        cin >> x;
    if (k == 0) {
        cout << n << "\n";
        for (int i = 0; i < n; i++)
            cout << i+1 << " ";
        cout << "\n";
        return;
    }
    int m = 32-__builtin_clz(k);
    unordered_map<int,vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] >> m].push_back(i);
    }
    vector<int> res;
    for (auto& p : mp) {
        int mx = 0, mask = 0;
        pii r;
        unordered_map<int, int> st;
        for (int b = m-1; b >= 0; b--) {
            if (mx >= k)
                break;
            mask |= (1 << b);
            for (int i = 0; i < (int)p.second.size(); i++) {
                st[a[p.second[i]] & mask] = p.second[i];
            }
            int new_mx = mx | (1 << b);
            for (pii pr : st) {
                if (st.find(new_mx ^ pr.first) != st.end()) {
                    mx = new_mx;
                    r = {st[new_mx ^ pr.first], pr.second};
                    break;
                }
            }
            st.clear();
        }
        if (mx >= k) {
            res.push_back(r.first);
            res.push_back(r.second);
        } else {
            res.push_back(p.second[0]);
        }
    }
    if (res.size() < 2) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << "\n";
    for (int v : res)
        cout << v+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
