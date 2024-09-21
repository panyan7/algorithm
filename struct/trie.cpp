#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

template <int K>
struct Trie {
    struct Vertex {
        int nxt[K];
        int leaf = -1;
        Vertex() {
            fill(nxt, nxt + K, -1);
        }
    };
    vector<Vertex> trie;
    Trie() { trie.emplace_back(); }
    void add_string(const string& s, int idx = 0) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].nxt[c] == -1) {
                trie[v].nxt[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].nxt[c];
        }
        trie[v].leaf = idx;
    }
    int find(const string& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].nxt[c] == -1)
                return -1;
            v = trie[v].nxt[c];
        }
        return v;
    }
    bool search(const string& s) {
        int v = find(s);
        return v != -1 && (trie[v].leaf != -1);
    }
    bool has_prefix(const string& s) {
        int v = find(s);
        return v != -1;
    }
};

const int K = 26;
using trie = Trie<K>;
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
