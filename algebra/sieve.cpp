#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
const int MAXN = 2e5+10;

int tt = 1, n, m, k;
bool is_composite[MAXN];
vector<int> prime;

void sieve(int n) {
    memset(is_composite, 0, sizeof(is_composite));
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i])
            prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0)
                break;
		}
	}
}

void sieve2(int m) {
    memset(is_composite, 0, sizeof(is_composite));
    for (int i = 2; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            is_composite[j] = true;
        }
    }
}

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    sieve(MAXN);
    while (tt--) {
        solve();
    }
    return 0;
}
