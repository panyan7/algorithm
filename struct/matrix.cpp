#include <bits/stdc++.h>
using namespace std;

template <int MOD> 
struct matrix {
    vector<vector<int>> data;
    int m, n;
    matrix(int x, int y) {
        m = x;
        n = y;
        data = vector<vector<int>> (m, vector<int> (n, 0));
    }
    matrix(vector<vector<int>> a) {
        m = a.size();
        n = a[0].size();
        data = a;
    }
public:
    vector<int>& operator [] (size_t i) {
        return data[i];
    }
    matrix& resize(int x, int y, int val) {
        m = x;
        n = y;
        data.assign(x, vector<int> (y, val));
    }
    matrix& operator += (matrix a) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = data[i][j];
                p -= MOD - a[i][j];
                p = (p < 0 ? p + MOD : p);
                data[i][j] = p;
            }
        }
        return *this;
    }
    matrix& operator -= (matrix a) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = data[i][j];
                p -= a[i][j];
                p = (p < 0 ? p + MOD : p);
                data[i][j] = p;
            }
        }
        return *this;
    }
    matrix& operator *= (int c) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = int(int64_t(data[i][j]) * int64_t(c) % MOD);
            }
        }
        return *this;
    }
    matrix& operator /= (int c) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = int(int64_t(data[i][j]) / int64_t(c) % MOD);
            }
        }
        return *this;
    }
    friend matrix operator + (const matrix& a, const matrix& b) {
        return matrix(a) += b;
    }
    friend matrix operator - (const matrix& a, const matrix& b) {
        return matrix(a) -= b;
    }
    friend matrix operator * (const matrix& a, const int c) {
        return matrix(a) *= c;
    }
    friend matrix operator / (const matrix& a, const int c) {
        return matrix(a) /= c;
    }
    friend matrix operator * (matrix& a, matrix& b) {
        assert(a.n == b.m);
        matrix product = matrix (a.m, b.n);
        for (int i = 0; i < a.m; ++i) {
            for (int j = 0; j < b.n; ++j) {
                for (int k = 0; k < b.n; ++k) {
                    int p = product[i][k];
                    p -= MOD - (a[i][j] * b[j][k] % MOD);
                    p = (p < 0 ? p + MOD : p);
                    product[i][k] = p;
                }
            }
        }
        return product;
    }
    matrix& operator *= (matrix& a) {
        assert(n == a.m);
        matrix b = matrix (*this);
        *this = b * a;
        return *this;
    }
    friend matrix pow(matrix a, int e) {
        matrix res = matrix (a.m, a.n);
        res[0][0] = res[1][1] = 1;
        while (e) {
            if (e % 2) {
                res *= a;
            }
            e /= 2;
            a *= a;
        }
        return res;
    }
};

int main() {
    typedef matrix<(int)1e9+7> mat;
    mat m = mat(2, 2);
    m[0][0] = m[1][1] = 2;
    cout << pow(m, 10)[0][0] << " " << (m * m)[1][1] << endl;
    return 0;
}
