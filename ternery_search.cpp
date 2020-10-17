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

/** Examples **/
int main() {
    int b[] = {1, 3, 5, 6, 9, 14, 13, 10, 9, 3};
    vector<int> a (b, b+10);
    cout << ternery_search(a) << endl; // 5
    return 0;
}
