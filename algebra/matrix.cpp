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
    T& operator [] (pair<int, int> id) { return data[id.first][id.second]; }
    Matrix tp() {
        // Transpose the Matrix
        Matrix<T> res(n, m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                res[j][i] = data[i][j];
        return res;
    }
    Matrix& assign(int x, int y, T val) {
        m = x, n = y;
        data = vector<vector<T>> (x, vector<T> (y, val));
        return *this;
    }
    Matrix& resize(int x, int y) {
        assert(m * n == x * y);
        vector<vector<T>> data_n(x, vector<T>(y));
        for (int i = 0; i < m * n; i++) {
            data_n[i / y][i % y] = data[i / n][i % n];
        }
        data = data_n;
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
template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int(v_ % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

const int MOD = 1e9+7;
using num = ModNum<MOD>;
using mat = Matrix<num>;
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
