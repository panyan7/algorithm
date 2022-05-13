#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct MinStack {
    stack<pii> st;
    void push(int x) {
        int new_min = st.empty() ? x : min(x, st.top.second);
        st.push({x, new_min});
    }
    int pop() {
        int x = st.top().first;
        st.pop();
        return x;
    }
    int get_min() {
        return st.top().second;
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
