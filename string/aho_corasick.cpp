#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const int K = 26;
struct Vertex {
    int nxt[K];
    int output = -1;
    int p = -1;
    char pch;
    int link = -1;
    int output_link = -1;
    int go[K];
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(nxt, nxt + K, -1);
        fill(go, go + K, -1);
    }
};
class ACAuto {
public:
    ACAuto() { trie.emplace_back(); }
    vector<Vertex> trie;
    void add_string(string const& s, int idx) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].nxt[c] == -1) {
                trie[v].nxt[c] = trie.size();
                trie.emplace_back(v, ch);
            }
            v = trie[v].nxt[c];
        }
        trie[v].output = idx;
    }
    int get_link(int v) {
        if (trie[v].link == -1) {
            if (v == 0 || trie[v].p == 0)
                trie[v].link = 0;
            else
                trie[v].link = go(get_link(trie[v].p), trie[v].pch);
        }
        return trie[v].link;
    }
    int get_output_link(int v) {
        if (v == 0)
            return trie[v].output_link = 0;
        if (trie[v].output_link == -1) {
            int u = get_link(v);
            if (trie[u].output != -1)
                trie[v].output_link = u;
            else
                trie[v].output_link = get_output_link(u);
        }
        return trie[v].output_link;
    }
    int go(int v, char ch) {
        int c = ch - 'a';
        if (trie[v].go[c] == -1) {
            if (trie[v].nxt[c] != -1)
                trie[v].go[c] = trie[v].nxt[c];
            else
                trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return trie[v].go[c];
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
