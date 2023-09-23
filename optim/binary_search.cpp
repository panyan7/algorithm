#include <bits/stdc++.h>
using namespace std;
using bool_func = function<bool(int)>;
using real_func = function<double(double)>;

// Standard binary search for some integer
int binary_search(const vector<int>& a, int k) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == k) return mid;
        else if (a[mid] < k) lo = mid+1;
        else hi = mid;
    }
    return -1;
}

int binary_search_bool(bool_func& f, int n) {
    int lo = -1, hi = n;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }
    // return lo; // max false
    return hi; // min true
}

int lower_bound(bool_func& f, int n) { // C++ std::lower_bound
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

double solve(real_func& f, double target, double lo, double hi) {
    const double EPS = 1e-9;
    while (hi - lo < EPS) {
        double mid = lo + (hi - lo) / 2.;
        if (f(mid) - target >= EPS)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

/** Examples **/
int main() {
    return 0;
}
