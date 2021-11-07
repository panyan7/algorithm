#include <bits/stdc++.h>
using namespace std;

/**
 * Knuth-Morris-Pratt algorithm for finding the occurrence of a certain word 
 * from some text.
 */
int kmp_search(string s, string w) {
    int m = s.size(), n = w.size();
    if (n == 0) return 0;

    // compute table using two pointers
    int t[n];
    t[0] = -1; // must restart all
    for (int p = 1, q = 0; p < n; ++p, ++q) {
        if (w[p] == w[q]) t[p] = t[q];
        else {
            t[p] = q;
            q = t[q];
            while (q >= 0 && w[p] != w[q]) q = t[q];
        }
    }

    // search
    for (int i = 0, j = 0; i < m; ) {
        if (w[j] == s[i]) {
            ++i; ++j;
            if (j == n) return i-j; // found
        } else {
            assert(j < n);
            j = t[j];
            if (j < 0) { // start again
                ++i; ++j;
            }
        }
    }
    return -1;
}
