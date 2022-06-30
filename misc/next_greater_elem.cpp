#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> l(n), r(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        l[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        r[i] = st.empty() ? n-1 : st.top() - 1;
        st.push(i);
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
