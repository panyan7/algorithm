#include <bits/stdc++.h>
using namespace std;

const int mod = 11; // Some prime number

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

int inverse(int x) { // Only holds when mod is prime
    return expmod(x, mod-2);
}

int main() {
    cout << expmod(5, 6) << endl;
    cout << inverse(3) << endl;
    return 0;
}
