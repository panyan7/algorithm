#include <bits/stdc++.h>
using namespace std;

template <int MOD> 
struct matrix {
    int m, n;
    vector<vector<int>> data;
    matrix(size_t x, size_t y) {
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
    matrix& resize(size_t x, size_t y, int val) {
        m = x;
        n = y;
        data = vector<vector<int>> (x, vector<int> (y, val));
        return *this;
    }
    static matrix I(int x) {
        matrix res (x, x);
        for (int i = 0; i < x; ++i) {
            res[i][i] = 1;
        }
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
        size_t m, n;
        i >> m >> n;
        a = matrix(m, n);
        for (int k = 0; k < m; ++k) {
            for (int j = 0; j < n; ++j) {
                i >> a[k][j];
            }
        }
        return i;
    }
    matrix& operator += (const matrix& a) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = data[i][j];
                p -= MOD - a.data[i][j];
                p = (p < 0 ? p + MOD : p);
                data[i][j] = p;
            }
        }
        return *this;
    }
    matrix& operator -= (const matrix& a) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = data[i][j];
                p -= a.data[i][j];
                p = (p < 0 ? p + MOD : p);
                data[i][j] = p;
            }
        }
        return *this;
    }
    matrix& operator += (int c) {
        c %= MOD;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = data[i][j];
                p -= MOD - c;
                p = (p < 0 ? p + MOD : p);
                data[i][j] = p;
            }
        }
        return *this;
    }
    matrix& operator -= (int c) {
        c %= MOD;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int p = data[i][j];
                p -= c;
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
        for (int i = 0; i < a.m; ++i) {
            for (int j = 0; j < b.m; ++j) {
                for (int k = 0; k < b.n; ++k) {
                    int p = prod[i][k];
                    p -= MOD - (a.data[i][j] * b.data[j][k] % MOD);
                    p = (p < 0 ? p + MOD : p);
                    prod[i][k] = p;
                }
            }
        }
        return prod;
    }
    friend matrix pow(const matrix& a, int e) {
        assert(a.m == a.n);
        matrix res = I(a.m);
        matrix b (a.data);
        while (e) {
            if (e % 2) {
                res = res * b;
            }
            e /= 2;
            b = b * b;
        }
        return res;
    }
};

int main() {
    typedef matrix<(int)1e9+7> mat;
    mat m = mat(2, 2);
    m[0][0] = m[1][1] = 2;
    cout << pow(m, 10);
    cout << (m * m) << endl;
    m += m;
    cout << m << endl;
    m += 2;
    cout << m << endl;
    m /= 2;
    cout << m << endl;
    return 0;
}
