/*
 *  Reference solution using 2-SAT
 *  GCPC 2022 G "Guessing Game"
 *  https://codeforces.com/gym/104059/problem/G
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
class SAT {
    int n;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;
private:
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }
    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }
public:
    SAT(int n_) : n(2*n_), adj(n), adj_t(n) {}
    bool solve() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs1(i);
        }
        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }
        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }
    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2*a ^ na;
        b = 2*b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};
 
int tt = 1, n, m, k;
 
void solve() {
    cin >> m;
    vector<int> d(7), p(7, 0);
    for (int i = 0; i < 7; i++) {
        cin >> d[i];
        n += d[i];
    }
    SAT G(n);
    for (int i = 1; i < 7; i++)
        p[i] = p[i-1] + d[i-1];
    vector<vector<int>> b(m, vector<int>(7, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> b[i][j];
        }
        for (int j = 0; j < 7; j++) {
            for (int k = j+1; k < 7; k++) {
                G.add_disjunction(abs(b[i][j]) + p[j] - 1, b[i][j] > 0, abs(b[i][k]) + p[k] - 1, b[i][k] > 0);
            }
        }
    }
    int b6, b7;
    cin >> b6 >> b7;
    G.add_disjunction(abs(b6) + p[5] - 1, b6 < 0, abs(b7) + p[6] - 1, b7 < 0);
    G.add_disjunction(abs(b6) + p[5] - 1, b6 > 0, abs(b7) + p[6] - 1, b7 < 0);
    G.add_disjunction(abs(b6) + p[5] - 1, b6 < 0, abs(b7) + p[6] - 1, b7 > 0);
    bool res = G.solve();
    if (res)
        cout << "possible\n";
    else
        cout << "impossible\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
