#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()
#define F_OR1(n) for (int i = 0; i < n; ++i)
#define F_OR2(i, n) for (int i = 0; i < n; ++i)
#define F_OR3(i, k, n) for (int i = k; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define F_OR(...) GET_MACRO(__VA_ARGS__, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_OR(__VA_ARGS__) (__VA_ARGS__)
#define EACH(x, a) for (auto& x : a)
const int MOD = 1e9+7;

template <typename T> 
struct matrix {
    int m, n;
    vector<vector<T>> data;
    matrix(size_t x, size_t y) {
        m = x, n = y;
        data.assign(m, vector<T> (n, (T)0));
    }
    matrix(size_t x, size_t y, T val) {
        m = x, n = y;
        data.assign(m, vector<T> (n, val));
    }
    matrix(vector<vector<T>> a) {
        m = a.size(), n = a[0].size();
        data = a;
    }
public:
    vector<T>& operator [] (size_t i) { return data[i]; }
    int& operator [] (pair<int, int> id) { return data[id.first][id.second]; }
    friend matrix& t(const matrix& a) {
        // Transpose the matrix
        matrix<T> res (a.n, a.m);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < a.n; ++j)
                res[j][i] = a.data[i][j];
        return res;
    }
    matrix& resize(size_t x, size_t y, T val) {
        m = x, n = y;
        data = vector<vector<T>> (x, vector<T> (y, val));
        return *this;
    }
    static matrix I(size_t n) {
        matrix res (n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = 1;
        return res;
    }
    static matrix I(size_t n, T one) {
        matrix res (n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = one;
        return res;
    }
    friend ostream& operator << (ostream& o, const matrix& a) {
        for (int i = 0; i < a.m; ++i) {
            for (int j = 0; j < a.n; ++j) {
                o << a.data[i][j];
                o << (j == a.n-1 ? "\n" : " ");
            }
        }
        return o;
    }
    friend istream& operator >> (istream& i, const matrix& a) {
        size_t m, n; i >> m >> n;
        a = matrix(m, n);
        for (int k = 0; k < m; ++k)
            for (int j = 0; j < n; ++j)
                i >> a[k][j];
        return i;
    }
    matrix& operator += (const matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += o.data[i][j];
        return *this;
    }
    matrix& operator -= (const matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= o.data[i][j];
        return *this;
    }
    matrix& operator += (T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += c;
        return *this;
    }
    matrix& operator -= (T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= c;
        return *this;
    }
    matrix& operator *= (int c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] *= c;
        return *this;
    }
    matrix& operator /= (int c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] /= c;
        return *this;
    }
    friend matrix operator + (const matrix& a, const matrix& b) {
        return matrix(a) += b;
    }
    friend matrix operator - (const matrix& a, const matrix& b) {
        return matrix(a) -= b;
    }
    friend matrix operator + (const matrix& a, const int c) {
        return matrix(a) += c;
    }
    friend matrix operator - (const matrix& a, const int c) {
        return matrix(a) -= c;
    }
    friend matrix operator * (const matrix& a, const int c) {
        return matrix(a) *= c;
    }
    friend matrix operator / (const matrix& a, const int c) {
        return matrix(a) /= c;
    }
    friend matrix operator * (const matrix& a, const matrix& b) {
        assert(a.n == b.m);
        matrix prod (a.m, b.n);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < b.n; ++k)
                    prod[i][k] += a.data[i][j] * b.data[j][k];
        return prod;
    }
    friend matrix pow(const matrix& a, int e) {
        assert(a.m == a.n);
        matrix res = I(a.m), b = a;
        while (e) {
            if (e % 2) res = res * b;
            e /= 2;
            b = b * b;
        }
        return res;
    }
};

int t;

void solve() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
