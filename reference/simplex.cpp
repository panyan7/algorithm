/**
 *  Reference solution using simplex algorithm for linear programming
 *  15-451 Fall 2021 Homework 6 Programming "A Cop and a Robber"
 *  https://www.cs.cmu.edu/~15451-f21/hws/hw6.pdf
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Simplex algorithm for solving linear programming
// maximize <c, x>
// subject to Ax <= b
// m constraints, n variables
struct Simplex {
public:
    int m, n;
    vector<vector<double>> A;
    vector<int> basic;                  // size m.  indices of basic vars
    vector<int> nonbasic;               // size n.  indices of non-basic vars
    vector<double> soln;
    double z;                           // return value of the objective function.
    int lp_type;                        // for return.  1 if feasible, 0 if not feasible, -1 if unbounded
    const double INF = 1e100;
    const double EPS = 1e-9;
    const static int FEASIBLE = 1;
    const static int INFEASIBLE = 0;
    const static int UNBOUNDED = -1;
    Simplex(int m0, int n0, vector<vector<double>>& A0,
            vector<double>& B, vector<double>& C) :
            m(m0),
            n(n0),
            A(m0+1) {
        basic.resize(m0);
        nonbasic.resize(n0);
        soln.resize(n);
        for (int i = 0; i < A.size(); i++) {
            A[i].resize(n+1);
        }
        for (int j = 0; j < m; j++)
            basic[j] = n+j;
        for (int i = 0; i < n; i++)
            nonbasic[i] = i;
        for (int i = 0; i < m; i++) {
            A[i][n] = B[i];
            for (int j = 0; j < n; j++)
                A[i][j] = A0[i][j];
        }
        for (int j = 0; j < n; j++)
            A[m][j] = C[j];
        if (!Feasible()) {
            lp_type = INFEASIBLE;
            return;
        }
        while (true) {
            int r=0, c=0;
            double p = 0.0;
            for (int i = 0; i < n; i++) {
                if (A[m][i] > p)
                    p = A[m][c=i];
            }
            if (p < EPS) {
                for (int j = 0; j < n; j++)
                    if (nonbasic[j] < n)
                        soln[nonbasic[j]] = 0;
                for (int i = 0; i < m; i++)
                    if (basic[i] < n)
                        soln[basic[i]] = A[i][n];
                z = -A[m][n];
                lp_type = FEASIBLE;
                break;
            }
            p = INF;
            for (int i = 0; i < m; i++) {
                if (A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if (v < p) {p = v; r = i;}
                }
            }
            if (p == INF) {
                lp_type = UNBOUNDED;
                break;
            }
            Pivot(r,c);
        }
    }
private:
    void printa() {
        int i, j;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                printf("A[%d][%d] = %f\n", i, j, A[i][j]);
            }
        }
    }
    void Pivot(int r, int c) {
        //printf("pivot %d %d\n", r, c);
        //printa();
        swap(basic[r], nonbasic[c]);
        A[r][c] = 1 / A[r][c];
        for (int j = 0; j <= n; j++) {
            if (j != c)
                A[r][j] *= A[r][c];
        }
        for (int i = 0; i <= m; i++) {
            if (i != r) {
                for (int j = 0; j <= n; j++) {
                    if (j != c)
                        A[i][j] -= A[i][c] * A[r][j];
                }
                A[i][c] = -A[i][c] * A[r][c];
            }
        }
    }
    bool Feasible() {
        int r = 0, c = 0;
        while (true) {
            double p = INF;
            for (int i = 0; i < m; i++) 
                if (A[i][n] < p)
                    p = A[r=i][n];
            if (p > -EPS)
                return true;
            p = 0.0;
            for (int i = 0; i < n; i++)
                if (A[r][i] < p)
                    p = A[r][c=i];
            if (p > -EPS)
                return false;
            p = A[r][n] / A[r][c];
            for (int i = r+1; i < m; i++) {
                if (A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if (v < p) {
                        p = v;
                        r = i;
                    }
                }
            }
            Pivot(r,c);
        }
    }
};

int tt = 1, n, m, z;
int d[305][305], win[305][305];

void solve() {
    int dcop, drob;
    cin >> n >> m >> drob >> dcop;
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d[u][v] = 1;
        d[v][u] = 1;
    }
    // first compute shortest distance using Floyd-Warshall
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool can = false;
            for (int k = 0; k < n; k++) {
                if (d[i][k] > drob)
                    continue;
                if (d[j][k] > dcop)
                    can = true;
            }
            win[i][j] = can;
        }
    }
    vector<vector<double>> A(n+2, vector<double>(n+1, 0.0));
    vector<double> b(n+2, 0.0);
    vector<double> c(n+1, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (win[j][i])
                A[i][j] = -1.0;
        }
        A[i][n] = 1.0;
    }
    for (int j = 0; j < n; j++) {
        A[n][j] = -1.0;
        A[n+1][j] = 1.0;
    }
    b[n] = -1.0;
    b[n+1] = 1.0;
    c[n] = 1.0;
    Simplex solver = Simplex(n+2, n+1, A, b, c);
    cout << fixed << setprecision(10) << solver.soln[n] << "\n";
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
