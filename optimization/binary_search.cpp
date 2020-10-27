#include <bits/stdc++.h>
using namespace std;

// Standard binary search for some integer
int binary_search(vector<int> a, int k) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        //@loop_invariant A[0:lo) < k, A[hi, n) > k
        int mid = lo + (hi - lo) / 2; // avoid overflow
        if (a[mid] == k) return mid;
        else if (a[mid] < k) lo = mid+1;
        else hi = mid;
    }
    return -1;
}

// Binary search to find boundary of monotonic function
bool check(int k) {
    return k > 1000;
}

// Find minimum true
int binary_search_true(int n) {
    int lo = 0, hi = n;
    if (check(lo)) return lo;
    if (!check(hi)) return -1; // no solution
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return hi;
}

// Find maximum false
int binary_search_false(int n) {
    int lo = 0, hi = n;
    if (check(lo)) return -1;
    if (!check(hi)) return hi;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

/** Examples **/
int main() {
    int b[] = {1, 2, 5, 12, 34, 35, 45, 47, 51, 59, 80};
    vector<int> a (b, b+11);
    cout << binary_search(a, 35) << endl; // 5
    cout << binary_search(a, 37) << endl; // -1
    cout << binary_search_true(10000) << endl;
    cout << binary_search_false(10000) << endl;
    return 0;
}
