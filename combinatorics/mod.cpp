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

pair<int, int> exgcd(int a, int b) {
    if (b == 0) return make_pair(1, 0);
    auto r = exgcd(b, a%b);
    return make_pair(r.second, r.first - (a/b)*r.second);
}

int inv(int a) {
    auto r = exgcd(a, mod);
    return (r.first % mod + mod) % mod;
}

int main() {
    cout << expmod(5, 6) << endl;
    cout << inverse(3) << endl;
    cout << inv(3) << endl;
    return 0;
}
