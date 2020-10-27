#include <bits/stdc++.h>
using namespace std;

vector<int> f (1, 1); // Memoization to save time

int factorial(int n) {
    int m = f.size();
    f.resize(n+1);
    for (int i = m; i <= n; ++i) {
        f[i] = f[i-1] * i;
    }
    return f[n];
}

/** Examples **/
int main() {
    cout << factorial(2) << " " << factorial(5) << " " << factorial(10) << endl;
    for (auto i : f) cout << i << " ";
    return 0;
}
