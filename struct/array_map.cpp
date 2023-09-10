#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

template <typename T, int LB = 0, int UB = 0>
struct ArrayMap {
    int lb = LB, ub = UB;
    vector<T> data;
    ArrayMap() : data(ub-lb+1) {}
    ArrayMap(int lb_, int ub_) : lb(lb_), ub(ub_), data(ub-lb+1) {}
    ArrayMap(int lb_, int ub_, T v) : lb(lb_), ub(ub_), data(ub-lb+1, v) {}
    const size_t size() const                     { return data.size();     }
    T& operator[](size_t i)                       { return data[(int)i-lb]; }
    const T& operator[](size_t i) const           { return data[(int)i-lb]; }
    typename vector<T>::iterator begin()          { return data.begin();    }
    typename vector<T>::iterator end()            { return data.end();      }
    typename vector<T>::reverse_iterator rbegin() { return data.rbegin();   }
    typename vector<T>::reverse_iterator rend()   { return data.rend();     }
    friend ostream& operator<<(ostream& os, const ArrayMap& mp) {
        for (int i = 0; i < mp.size(); i++)
            os << mp[i] << " ";
        return os;
    }
};

int tt = 1, n, m, k;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
