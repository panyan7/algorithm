#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

template <typename T> 
struct Matrix {
    vector<vector<T>> a;
    int m, n;
    Matrix<T>(int x, int y) {
        this->m = x;
        this->n = y;
        this->a = vector<vector<T>> (m, vector<T> (n, 0));
    }
    Matrix<T> operator*(Matrix<T> other) {
        assert(this->n == other.m);
        Matrix<T> product = Matrix<T> (this->m, other.n);
        for (int i = 0; i < this->m; i++) {
            for (int j = 0; j < this->n; j++) {
                for (int k = 0; k < other.n; k++) {
                    product.a[i][k] += this->a[i][j] * other.a[j][k];
                    product.a[i][k] %= mod;
                }
            }
        }
        return product;
    }
};

template<typename T>
Matrix<T> expo(Matrix<T> a, int e) {
    Matrix<T> res = Matrix<T>(a.m, a.n);
	res.a[0][0] = res.a[1][1] = 1;
	while (e) {
		if (e % 2) {
			res = res * a;
		}
		e /= 2;
		a = a * a;
	}
	return res;
}

int main() {
    Matrix<int> m = Matrix<int>(2, 2);
    m.a[0][0] = 2;
    m.a[1][1] = 2;
    cout << expo(m, 10).a[0][0] << " " << (m * m).a[1][1] << endl;
    return 0;
}
