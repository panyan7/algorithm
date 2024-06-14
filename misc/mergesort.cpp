#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

long long _mergesort(vector<int>& arr, vector<int>& temp, int l, int r);
long long merge(vector<int>& arr, vector<int>& temp, int l, int mid, int r);
long long mergesort(vector<int>& arr) {
    int array_size = arr.size();
    vector<int> temp(array_size);
    return _mergesort(arr, temp, 0, array_size-1);
}
long long _mergesort(vector<int>& arr, vector<int>& temp, int l, int r) {
    int mid;
    long long inv_count = 0;
    if (r > l) {
        mid = (r + l) / 2;
        inv_count += _mergesort(arr, temp, l, mid);
        inv_count += _mergesort(arr, temp, mid + 1, r);
        inv_count += merge(arr, temp, l, mid + 1, r);
    }
    return inv_count;
}
long long merge(vector<int>& arr, vector<int>& temp, int l, int mid, int r) {
    int i, j, k;
    long long inv_count = 0;
    i = l;
    j = mid;
    k = l;
    while ((i <= mid - 1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

int tt = 1, n, m;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
