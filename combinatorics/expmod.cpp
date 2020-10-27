#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int expmod(int a, int b) {
    int res = 1 % mod;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}


int main() {
    cout << expmod(5, 6) << endl;
    return 0;
}
