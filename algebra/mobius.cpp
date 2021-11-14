#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
const int MAXN = 2e5+10;

int tt = 1, n, m, k;
int mob[MAXN];

void mobius() {
    mob[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        mob[i]--;
        for (int j = i + i; j < MAXN; j += i) {
            mob[j] -= mob[i];
        }
    }
}

// check long long
void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    mobius();
    while (tt--) {
        solve();
    }
    return 0;
}
