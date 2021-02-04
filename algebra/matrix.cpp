#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T> 
struct Matrix {
    int m, n;
    vector<vector<T>> data;
    Matrix(int x, int y) : m(x), n(y) {
        data.assign(m, vector<T>(n, (T)0));
    }
    Matrix(int x, int y, T val) : m(x), n(y) {
        data.assign(m, vector<T>(n, val));
    }
    Matrix(const vector<vector<T>>& a) : m(a.size()), n(a[0].size()) {
        data = a;
    }
public:
    vector<T>& operator [] (int i) { return data[i]; }
    int& operator [] (pair<int, int> id) { return data[id.first][id.second]; }
    friend Matrix& t(const Matrix& a) {
        // Transpose the Matrix
        Matrix<T> res(a.n, a.m);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < a.n; ++j)
                res[j][i] = a.data[i][j];
        return res;
    }
    Matrix& resize(int x, int y, T val) {
        m = x, n = y;
        data = vector<vector<T>> (x, vector<T> (y, val));
        return *this;
    }
    static Matrix I(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = 1;
        return res;
    }
    static Matrix I(int n, T one) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = one;
        return res;
    }
    friend ostream& operator<<(ostream& os, const Matrix& a) {
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < a.n; ++j)
                os << a.data[i][j] << (j+1 == a.n ? "\n" : " ");
        return os;
    }
    friend istream& operator>>(istream& is, const Matrix& a) {
        int m, n;
        is >> m >> n;
        a = Matrix(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                is >> a[i][j];
        return is;
    }
    Matrix& operator+=(const Matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += o.data[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= o.data[i][j];
        return *this;
    }
    Matrix& operator+=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += c;
        return *this;
    }
    Matrix& operator-=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= c;
        return *this;
    }
    Matrix& operator*=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] *= c;
        return *this;
    }
    Matrix& operator/=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] /= c;
        return *this;
    }
    friend Matrix operator+(const Matrix& a, const Matrix& b) {
        return Matrix(a) += b;
    }
    friend Matrix operator-(const Matrix& a, const Matrix& b) {
        return Matrix(a) -= b;
    }
    friend Matrix operator+(const Matrix& a, T c) {
        return Matrix(a) += c;
    }
    friend Matrix operator-(const Matrix& a, T c) {
        return Matrix(a) -= c;
    }
    friend Matrix operator*(const Matrix& a, T c) {
        return Matrix(a) *= c;
    }
    friend Matrix operator/(const Matrix& a, T c) {
        return Matrix(a) /= c;
    }
    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        assert(a.n == b.m);
        Matrix prod (a.m, b.n);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < b.n; ++k)
                    prod[i][k] += a.data[i][j] * b.data[j][k];
        return prod;
    }
    friend Matrix operator==(const Matrix& a, const Matrix& b) {
        assert(a.n == b.n);
        assert(a.m == b.m);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < a.n; ++j)
                if (a[i][j] != b[i][j])
                    return false;
        return true;
    }
    friend Matrix operator!=(const Matrix& a, const Matrix& b) {
        return !(a == b);
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

using mat = Matrix<int>;
int t = 1, n, m, k, q;

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
