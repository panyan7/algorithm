#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define read(a) for (auto& x : a) cin >> x
#define write(a) for (auto& x : a) cout << x << " "; cout << "\n"

template<typename T> 
struct Matrix {
    int m, n;
    vector<vector<T>> data;
    Matrix (size_t x, size_t y) {
        m = x, n = y;
        data.assign(m, vector<T> (n, (T)0));
    }
    Matrix (size_t x, size_t y, T val) {
        m = x, n = y;
        data.assign(m, vector<T> (n, val));
    }
    Matrix (const vector<vector<T>>& a) {
        m = a.size(), n = a[0].size();
        data = a;
    }
public:
    vector<T>& operator [] (size_t i) { return data[i]; }
    int& operator [] (pair<int, int> id) { return data[id.first][id.second]; }
    friend Matrix& t(const Matrix& a) {
        // Transpose the Matrix
        Matrix<T> res (a.n, a.m);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < a.n; ++j)
                res[j][i] = a.data[i][j];
        return res;
    }
    Matrix& resize(size_t x, size_t y, T val) {
        m = x, n = y;
        data = vector<vector<T>> (x, vector<T> (y, val));
        return *this;
    }
    static Matrix I(size_t n) {
        Matrix res (n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = 1;
        return res;
    }
    static Matrix I(size_t n, T one) {
        Matrix res (n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = one;
        return res;
    }
    friend ostream& operator << (ostream& o, const Matrix& a) {
        for (int i = 0; i < a.m; ++i) {
            for (int j = 0; j < a.n; ++j) {
                o << a.data[i][j];
                o << (j == a.n-1 ? "\n" : " ");
            }
        }
        return o;
    }
    friend istream& operator >> (istream& i, const Matrix& a) {
        size_t m, n; i >> m >> n;
        a = Matrix(m, n);
        for (int k = 0; k < m; ++k)
            for (int j = 0; j < n; ++j)
                i >> a[k][j];
        return i;
    }
    Matrix& operator += (const Matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += o.data[i][j];
        return *this;
    }
    Matrix& operator -= (const Matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= o.data[i][j];
        return *this;
    }
    Matrix& operator += (T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += c;
        return *this;
    }
    Matrix& operator -= (T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= c;
        return *this;
    }
    Matrix& operator *= (int c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] *= c;
        return *this;
    }
    Matrix& operator /= (int c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] /= c;
        return *this;
    }
    friend Matrix operator + (const Matrix& a, const Matrix& b) {
        return Matrix(a) += b;
    }
    friend Matrix operator - (const Matrix& a, const Matrix& b) {
        return Matrix(a) -= b;
    }
    friend Matrix operator + (const Matrix& a, int c) {
        return Matrix(a) += c;
    }
    friend Matrix operator - (const Matrix& a, int c) {
        return Matrix(a) -= c;
    }
    friend Matrix operator * (const Matrix& a, int c) {
        return Matrix(a) *= c;
    }
    friend Matrix operator / (const Matrix& a, int c) {
        return Matrix(a) /= c;
    }
    friend Matrix operator * (const Matrix& a, const Matrix& b) {
        assert(a.n == b.m);
        Matrix prod (a.m, b.n);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < b.n; ++k)
                    prod[i][k] += a.data[i][j] * b.data[j][k];
        return prod;
    }
    friend Matrix pow(const Matrix& a, int e) {
        assert(a.m == a.n);
        Matrix res = I(a.m), b = a;
        while (e) {
            if (e % 2) res = res * b;
            e /= 2;
            b = b * b;
        }
        return res;
    }
};

typedef Matrix<int> mat;
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
