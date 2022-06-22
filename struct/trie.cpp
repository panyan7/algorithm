#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const int K = 26;
struct Vertex {
    int nxt[K];
    bool leaf = false;
    Vertex() {
        fill(nxt, nxt + K, -1);
    }
};
vector<Vertex> trie(1);
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].nxt[c] == -1) {
            trie[v].nxt[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].nxt[c];
    }
    trie[v].leaf = true;
}

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
