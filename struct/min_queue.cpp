#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct MinQueue {
    stack<pii> s1, s2;
    void push(int x) {
        int new_min = s1.empty() ? x : min(x, s1.top().second);
        s1.push({x, new_min});
    }
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top().first;
                s1.pop();
                int new_min = s2.empty() ? x : min(x, s2.top().second);
                s2.push({x, new_min});
            }
        }
        int x = s2.top().first;
        s2.pop();
        return x;
    }
    void get_min() {
        if (s1.empty() || s2.empty()) 
            return s1.empty() ? s2.top().second : s1.top().second;
        else
            return min(s1.top().second, s2.top().second);
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
