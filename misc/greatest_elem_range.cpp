#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    deque<int> q;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        if (!q.empty() && q.front() <= i-k)
            q.pop_front();
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        l[i] = q.front();
        // l[i] is index of the greatest element in (i-k, i]
        // typically used in dp
    }
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
