#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

template <typename T> 
struct matrix {
    vector<vector<T>> a;
    long long m, n;
    matrix<T>(long long x, long long y) {
        m = x;
        n = y;
        a = vector<vector<T>> (m, vector<T> (n, 0));
    }
    matrix<T> operator*(matrix<T> other) {
        assert(n == other.m);
        matrix<T> product = matrix<T> (m, other.n);
        for (long long i = 0; i < m; i++) {
            for (long long j = 0; j < n; j++) {
                for (long long k = 0; k < other.n; k++) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k] %= mod;
                }
            }
        }
        return product;
    }
};

template<typename T>
matrix<T> expo(matrix<T> a, long long e) {
    matrix<T> res = matrix<T>(a.m, a.n);
	res.a[0][0] = res.a[1][1] = 1;
	while(e) {
		if(e % 2) {
			res = res * a;
		}
		e /= 2;
		a = a * a;
	}
	return res;
}

int main() {
    matrix<int> m = matrix<int>(2, 2);
    m.a[0][0] = 2;
    m.a[1][1] = 2;
    cout << expo(m, 10).a[0][0] << " " << (m * m).a[1][1] << endl;
    return 0;
}
