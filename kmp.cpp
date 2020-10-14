#include <bits/stdc++.h>
using namespace std;

/**
 * Knuth-Morris-Pratt algorithm for finding the ocurrence of a certain word 
 * from some text.
 */
int kmp(string s, string w) {
  int m = s.size(), n = w.size();
  if (n == 0) return 0;

  // compute table using two pointers
  int t[n], p = 1, q = 0;
  t[0] = -1; // must restart all
  while (p < n) {
      if (w[p] == w[q]) t[p] = t[q];
      else {
          t[p] = q;
          q = t[q];
          while (q >= 0 && w[p] != w[q]) q = t[q];
      }
      p++;
      q++;
  }

  // search
  int i = 0, j = 0;
  while (i < m) {
      if (w[j] == s[i]) {
          i++;
          j++;
          if (j == n) return i-j; // found
      } else {
          assert(j < n);
          j = t[j];
          if (j < 0) { // start again
              i++;
              j++;
          }
      }
  }
  return -1;
}
