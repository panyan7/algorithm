#include <bits/stdc++.h>
using namespace std;

int ternery_search(vector<int> a) {
    int lo = 0, hi = a.size()-1;
    while (lo + 2 < hi) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        if (a[mid1] <= a[mid2]) lo = mid1;
        else hi = mid2;
    }
    int mid = lo + (hi-lo)/2;
    if (a[mid] >= a[lo] && a[mid] >= a[hi]) {
        return mid;
    } else {
        if (a[lo] > a[hi]) return lo;
        else return hi;
    }
}

