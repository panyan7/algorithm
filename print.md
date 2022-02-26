# Algorithms
I'm a noob who only started doing competitive programming during sophomore year in college. I collected several useful algorithms and tips in this repo for me to use in contests. All of them are implemented in C++. 
Many of them are adapted from [CP Algorithms](https://cp-algorithms.com/index.html) and various [Codeforces](https://codeforces.com/) posts. 

This repository is mainly for personal use. The codes might not be useful to others, but I'll make it public in case anyone needs it. I added my own template and predefined a command to copy the file in my shell, so I can straightly work on these templates during a contest.

My homepage: [Yan Pan](https://panyan7.github.io/)

My Codeforces handles: [YanPan](https://codeforces.com/profile/YanPan).

## Full List of Algorithms

### Algebra
In directory `algebra/`

- Fast Fourier transform `fft.cpp`
- Fraction as pair of integers `frac.cpp`
- Gaussian elimination `gaussian_elim.cpp`
- Gaussian elimination with modular number `gaussian_elim_mod.cpp`
- Matrix with efficient multiplication and exponentiation `matrix.cpp`
- Finding maximum pairwise xor value in array `max_xor.cpp`
- M&ouml;bius inversion `mobius.cpp`
- Modular number with exponentiation and inverse `modnum.cpp`
- Number theoretic transform `ntt.cpp`
- Testing primality `prime_test.cpp`
- Prime factorization `prime_factorize.cpp`
- Sieve of Eratosthenes `sieve.cpp`
- Sum over subsets `sos.cpp`
- Inverse sum over subsets `sos_inv.cpp`

### Combinatorics
In directory `combinatorics/`

- Stirling number of the second kind `stirling.cpp`


### Geometry
In directory `geometry/`

- Basic geometry operations `basic.cpp`
- Convex Hull `convex_hull.cpp`

### Graph Theory
In directory `graph/`

- Bellman-Ford algorithm with negative cycle detection `bellman_ford.cpp`
- Breadth-first search `bfs.cpp`
- Bridge finding `bridge.cpp`
- Bipartite graph testing with BFS `bipartite.cpp`
- Cycle detection with DFS `cycle.cpp`
- Cycle detection with DFS on undirected graph `cycle_ud.cpp`
- Depth-first search `dfs.cpp`
- Dijkstra's algorithm `dijkstra.cpp`
- Dijkstra's algorithm with priority queue `dijkstra_pq.cpp`
- Floyd-Warshall algorithm for all sources shortest path `floyd_warshall.cpp`
- Kahn's algorithm for topological sorting `kahn.cpp`
- Kruskal's algorithm for MST construction with union find `kruskal.cpp`
- Lowest common ancestor with binary lifting `lca.cpp`
- Longest path in a DAG `longest_path.cpp`
- Prim's algorithm for MST construction `prim.cpp`
- Strongly connected components with DFS `scc.cpp`
- Topological sorting with DFS `toposort.cpp`
- Union find `union_find.cpp`
- Union find as a struct `union_find_struct.cpp`

### Optimization
In directory `optim/`

- Binary search `binary_search.cpp`
- Dinic's algorithm for max flow `max_flow.cpp`
- Min cost flow or min cost max flow (supports both problems) `min_cost_flow.cpp`
- Simplex algorithm for linear programming `simplex.cpp`
- Ternary search `ternary_search.cpp`

### String
In directory `string/`

- Aho-Corasick algorithm for string searching `aho_corasick.cpp`
- Knuth-Morris-Pratt (KMP) algorithm for string searching `kmp.cpp`

### Data Structures
In directory `struct/`

- Fenwick tree `fenwick.cpp`
- Range minimum query `rmq.cpp`
- Segment tree with generic query function and assignment query `segtree.cpp`
- 2D Segment tree with generic query function and assignment query `segtree_2d.cpp`
- Segment tree with range add query and max query `segtree_range_add.cpp`
- Segment tree with range assignment query and sum query `segtree_range_assign.cpp`
- Splay tree `splay.cpp`
- Treap `treap.cpp`

### Generic Algorithm Design Techniques
In directory `technique/`

- Sweep Line `sweepline.cpp`
- Two pointers `two_pointers.cpp`

### Miscellaneous Important Problems
In directory `misc/`

- Longest increasing subsequence `lis.cpp`
- Maximum subarray sum `mss.cpp`

## Some Tips for Competitive Programming
### Algorithm Design Ideas
- Always think of two-pointers first when dealing with range and need a O(n) solution.
- Similarly, always think of sweepline when you can transform inputs into ranges explicitly and need to consider the intersection of them.
- You can also use sweepline to merge ranges.
- Binary search can be used on any monotonic sequences. This includes segment tree with range max/min query.
- Think of brute force, or if you can reduce the problem to a brute force problem with better input sizes.
- Monotonic stack is also useful when you want to merge some elements, or erase those such that their effect are covered by others.

### Utilizing Input Range
- It is important to read the input ranges correctly!
- When the problem only gives a few inputs, and the range of the input is something like 1e6, it is probably linear. If O(1) or O(log n) solutions exist, they would give 1e9 range.
- When the numbers are 1e6 or smaller, the solution is probably pseudo-polynomial time and depends on the size of these numbers. Because otherwise they would give numbers of 1e9.
- Typically when the list is 1e5 and the numbers are 1e9, you cannot do square root time operations like prime factorization. But if they are 1e6, you probably want to consider that.

### Writing Clean Code
- When you're making queries to sum of absolute values minus some number, you can precompute the points that the solution change, and calculate p, the number of positive - number of non-positive, and w, the sum of elements with signs +1 or -1. Then, you can calculate the query x by w - x * p. This is clean and easy to debug.
- Tree operations are slow in constant. So avoid using ordered set and map in general if you don't really need them. Vector + sort + removing duplicate with `a.erase(std::unique(a.begin(), a.end()), a.end())` is much faster than set in practice. Priority queue is also much faster than multiset, although their query complexities are both O(log n).
- If you want to calculate both the prefix and suffix quickly, you just need one prefix sum array. When you have fewer arrays, you don't have to modify a lot during debugging. Also, if you only need prefix sum, you can do stuff like `a[i] += a[i-1]` for each 
- When you binary search for a fixed precision, you can run for a fixed iteration, which is something at least log(precision). Typically something like 100 works.

### Debugging
- Did you use long long? Especially, when you do bitwise shift, use 1LL.
- Did you confuse max and min?
- Did you confuse m and n?
- Are the containers initialized correctly? If there are multiple test cases, did you clear the containers?
- Are there array out of bound issues?
- Are the base case (and index) of dp correct?
- Did you do off by one for the index? Are the choices consistent throughout the program?
- Did you try test cases that cover all parts of your solution?
- Does the test case allow negative numbers and did you forget it?


\newpage

# misc/lis.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        // use lower_bound for increasing, upper_bound for non-decreasing
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        // auto it = upper_bound(d.begin(), d.end(), a[i]);
        if (it != d.end())
            *it = a[i];
        else
            d.push_back(a[i]);
    }
    // result is d.size()
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

```
\newpage

# misc/mss.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int c = 0, s = INT_MIN;
    for (int i = 0; i < n; i++) {
        c += a[i];
        s = max(s, c);
        c = max(c, 0);
    }
    // result is s
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

```
\newpage

# graph/dijkstra.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const ll INF = 1e9;
vector<vector<pll>> adj;
vector<ll> dist, p;

void dijkstra(vector<int>& source) {
    dist.assign(n, INF);
    p.assign(n, -1);
    vector<bool> vis(n, 0);
    for (int s : source)
        dist[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }
        if (d[v] == INF)
            break;
        vis[v] = true;
        for (auto e : adj[v]) {
            int u = e.first, w = e.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                p[u] = v;
            }
        }
    }
}

// check long long
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

```
\newpage

# graph/bipartite.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<vector<int>> adj;
    // make adj
    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    // is_bipartite: true if the graph is bipartite
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

```
\newpage

# graph/cycle.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis, anc;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (anc[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    anc[v] = false;
    return false;
}

bool find_cycle() {
    vis.assign(n, 0);
    anc.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (!vis[v] && dfs(v))
            break;
    }
    if (cycle_start == -1) // acyclic
        return false;
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    return true;
}

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

```
\newpage

# graph/scc.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj, adj_rev;
vector<bool> vis;
vector<int> order, components;
vector<vector<int>> res;
vector<unordered_set<int>> adj_contract;

void dfs1(int v) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    vis[v] = true;
    components.push_back(v);
    for (int u : adj_rev[v])
        if (!vis[u])
            dfs2(u);
}

// check long long
void solve() {
    cin >> n >> m;
    adj.clear();
    adj_rev.clear();
    adj.resize(n);
    adj_rev.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    vis.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs1(i);
    vis.assign(n, 0);
    reverse(order.begin(), order.end());
    vector<int> parent(n);
    int N = 0;
    for (int v : order) {
        if (!vis[v]) {
            dfs2(v);
            for (int v : components)
                parent[v] = N;
            N++;
            /*
            vector<int> temp;
            copy(components.begin(), components.end(), temp.begin());
            res.push_back(temp);
            */
            components.clear();
        }
    }
    // contract graph (optional)
    adj_contract.clear();
    adj_contract.resize(n);
    for (int v = 0; v < n; v++) {
        for (int u : adj[v])
            if (parent[u] != parent[v])
                adj_contract[parent[u]].insert(parent[v]);
    }
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

```
\newpage

# graph/floyd_warshall.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
const int INF = INT_MAX;
using edge = array<int,3>;

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<vector<pii>> adj;
    // make the adj list

    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    // d[i][j] shortest distance from i to j
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

```
\newpage

# graph/lca.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Lowest common ancestor with binary lifting
// O(n log n) build and O(log n) query
// The graph needs to be undirected
struct LCA {
    int n, lim;
    int timer = 0;
    vector<vector<int>> anc;
    vector<vector<int>> adj;
    vector<int> tin, tout;
private:
    void dfs(int v, int p) {
        tin[v] = ++timer;
        anc[v][0] = p;
        for (int i = 1; i <= lim; ++i)
            anc[v][i] = anc[anc[v][i-1]][i-1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    void print() {
        cout << "tin\n";
        for (int i = 0; i < n; i++)
            cout << tin[i] << " \n"[i+1==n];
        cout << "tout\n";
        for (int i = 0; i < n; i++)
            cout << tout[i] << " \n"[i+1==n];
        cout << "anc\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= lim; j++)
                cout << anc[i][j] << " \n"[j==lim];
        }
    }
public:
    LCA(int n_) : n(n_), lim(ceil(log2(n_))) {
        tin.assign(n, 0);
        tout.assign(n, 0);
        adj.resize(n);
        anc.assign(n, vector<int>(lim+1, 0));
    }
    void init(int root = 0) {
        dfs(root, root);
    }
    int query(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = lim; i >= 0; --i) {
            if (!is_ancestor(anc[u][i], v))
                u = anc[u][i];
        }
        return anc[u][0];
    }
};

int tt = 1, n, m, q;

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

```
\newpage

# graph/dijkstra_pq.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const ll INF = 1e15; // Large value, INT_MAX may cause overflow
vector<vector<pll>> adj;
vector<ll> dist, p;

void dijkstra(vector<int>& source) {
    dist.assign(n, INF);
    p.assign(n, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int s : source) {
        pq.push({0, s});
        dist[s] = 0;
    }
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (dist[v] != d) // Skip impossible paths
            continue;
        for (auto e : adj[v]) {
            ll u = e.first, w = e.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
}

// check long long
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

```
\newpage

# graph/union_find_struct.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;

struct DSU {
    int n;
    vector<int> parent, sz;
    DSU(int n_) : n(n_) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int v = 0; v < n; ++v)
            parent[v] = v;
    }
    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]); // Optimizes depth 
    }
    bool union_sets(int v, int u) {
        v = find_set(v), u = find_set(u);
        if (v == u)
            return false;
        if (sz[v] < sz[u])
            swap(v, u); // Optimizes depth
        parent[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

// check long long
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

```
\newpage

# graph/cycle_ud.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    vis[v] = true;
    for (int u : adj[v]) {
        if (u == par)
            continue; // skipping edge to parent vertex
        if (vis[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

bool find_cycle() {
    vis.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (!vis[v] && dfs(v, parent[v]))
            break;
    }
    if (cycle_start == -1)
        return false;
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    return true;
}

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

```
\newpage

# graph/bfs.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void bfs(int v) {
    int n = adj.size();
    vector<bool> vis (n, false);
    queue<int> q; q.push(v); vis[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto w : adj[u]) {
            if (!vis[w]) {
                q.push(w);
                vis[w] = true;
            }
        }
    }
}

```
\newpage

# graph/kruskal.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<array<ll,3>> edges;
vector<int> parent;
vector<int> sz;

void init() {
    parent.resize(n);
    sz.assign(n, 1);
    for (int v = 0; v < n; ++v)
        parent[v] = v;
}
int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]); // Optimizes depth 
}
bool union_sets(int v, int u) {
    v = find_set(v), u = find_set(u);
    if (v == u)
        return false;
    if (sz[v] < sz[u])
        swap(v, u); // Optimizes depth
    parent[u] = v;
    sz[v] += sz[u];
    return true;
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    ll cost = 0;
    vector<array<ll,3>> res;
    for (array<ll,3> e : edges) {
        if (find_set(e[1]) != find_set(e[2])) {
            cost += e[0];
            res.push_back(e);
            union_sets(e[1], e[2]);
        }
        if (res.size() >= n-1)
            break;
    }
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

```
\newpage

# graph/longest_path.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> vis, anc, ord;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (auto u : adj[v]) {
        if (!vis[u] && !dfs(u))
            return false;
        else if (anc[u])
            return false;
    }
    anc[v] = false;
    ord.push_back(v);
    return true;
}
bool topological_sort() {
    //vis.assign(n, false);
    ord.clear();
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            bool res = dfs(i);
            if (!res)
                return false;
        }
    }
    reverse(ord.begin(), ord.end());
    return true;
}

void solve() {
    // first do topological sort
    // then do dp
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

```
\newpage

# graph/dfs.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int v) {
    stack<int> s;
    s.push(v);
    vis[v] = true;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (auto w : adj[u]) {
            if (!vis[w]) {
                s.push(w);
                vis[w] = true;
            }
        }
    }
}

void dfs_rec(int v) {
    vis[v] = true;
    for (auto u : adj[v])
        if (!vis[u])
            dfs_rec(u);
}


```
\newpage

# graph/kahn.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> kahn_topo_sort(vector<vector<int>> G) {
    int n = G.size();
    vector<int> in_deg (n, 0);
    for (int i = 0; i < n; ++i) 
        for (int v : G[i])
            in_deg[v]++;
    queue<int> q;
    vector<int> res;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (in_deg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (int u : G[v])
            if (--in_deg[u] == 0)
                q.push(u);
        cnt++;
    }
    if (cnt == n)
        return res;
    else // exists cycle
        return vector<int> (0);
}

```
\newpage

# graph/bridge.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pt;
vector<vector<int>> G;
vector<bool> visited;
vector<int> tin, low;
int n, timer, num_bridges, num_comp;

void dfs(int v, int p) {
    visited[v] = true;
    tin[v] = timer; low[v] = timer; timer++;
    for (auto u : G[v]) {
        if (u == p) continue;
        if (visited[u]) low[v] = min(low[v], tin[u]);
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) num_bridges++;
        }
    }
}

void bridge(int v) {
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && !G[i].empty()) {
            num_comp++;
            dfs(i, -1);
        }
    }
}

```
\newpage

# graph/union_find.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<int> parent;
vector<int> sz;

void init() {
    parent.resize(n);
    sz.assign(n, 1);
    for (int v = 0; v < n; ++v)
        parent[v] = v;
}
int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]); // Optimizes depth 
}
bool union_sets(int v, int u) {
    v = find_set(v), u = find_set(u);
    if (v == u)
        return false;
    if (sz[v] < sz[u])
        swap(v, u); // Optimizes depth
    parent[u] = v;
    sz[v] += sz[u];
    return true;
}

// check long long
void solve() {
    init();
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

```
\newpage

# graph/prim.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj; // adjacency matrix
const int INF = 0x3f3f3f3f;
// typedef pair<int, int> edge;

struct edge { int w = INF, to = 0; };

vector<pair<int, int>> prim() {
    int total = 0;
    vector<bool> selected (n+1, false);
    vector<edge> min_e(n+1);
    vector<pair<int, int>> res;
    min_e[1].w = 0;

    for (int i = 1; i <= n; ++i) {
        int v = 0;
        for (int j = 1; j <= n; ++j)
            if (!selected[j] && (v == 0 || min_e[j].w < min_e[v].w))
                v = j;

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            return res;
        }

        selected[v] = true;
        total += min_e[v].w;
        if (min_e[v].to != 0)
            res.push_back({v, min_e[v].to});
        for (int u = 1; u <= n; ++u)
            if (adj[v][u] < min_e[u].w)
                min_e[u] = {adj[v][u], v};
    }
    cout << total << endl;
    return res;
}

```
\newpage

# graph/bellman_ford.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const int INF = 1e9;
int n, m;
vector<array<ll,3>> edges;
vector<int> d;

void bellman_ford(int s) {
    d.assign(n+1, INF);
    d[s] = 0;
    for (int k = 1; k <= n-1; ++k) {
        bool upd = false;
        for (auto e : edges) {
            if (d[e[0]] < INF) {
                if (d[e[1]] > d[e[0]] + e[2]) {
                    d[e[1]] = d[e[0]] + e[2];
                    upd = true;
                }
            }
        }
        if (!upd) return;
    }
}

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

```
\newpage

# graph/toposort.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> vis, anc, ord;

bool dfs(int v) {
    vis[v] = true;
    anc[v] = true;
    for (auto u : adj[v]) {
        if (!vis[u] && !dfs(u))
            return false;
        else if (anc[u])
            return false;
    }
    anc[v] = false;
    ord.push_back(v);
    return true;
}
bool topological_sort() {
    //vis.assign(n, false);
    ord.clear();
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            bool res = dfs(i);
            if (!res)
                return false;
        }
    }
    reverse(ord.begin(), ord.end());
    return true;
}

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

```
\newpage

# optim/simplex.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Simplex algorithm for solving linear programming
// maximize <c, x>
// subject to Ax <= b
// m constraints, n variables
struct Simplex {
public:
    int m, n;
    vector<vector<double>> A;
    vector<int> basic;                  // size m.  indices of basic vars
    vector<int> nonbasic;               // size n.  indices of non-basic vars
    vector<double> soln;
    double z;                           // return value of the objective function.
    int lp_type;                        // for return.  1 if feasible, 0 if not feasible, -1 if unbounded
    const double INF = 1e100;
    const double EPS = 1e-9;
    const static int FEASIBLE = 1;
    const static int INFEASIBLE = 0;
    const static int UNBOUNDED = -1;
    Simplex(int m0, int n0, vector<vector<double>>& A0,
            vector<double>& B, vector<double>& C) :
            m(m0),
            n(n0),
            A(m0+1) {
        basic.resize(m0);
        nonbasic.resize(n0);
        soln.resize(n);
        for (int i = 0; i < A.size(); i++) {
            A[i].resize(n+1);
        }
        for (int j = 0; j < m; j++)
            basic[j] = n+j;
        for (int i = 0; i < n; i++)
            nonbasic[i] = i;
        for (int i = 0; i < m; i++) {
            A[i][n] = B[i];
            for (int j = 0; j < n; j++)
                A[i][j] = A0[i][j];
        }
        for (int j = 0; j < n; j++)
            A[m][j] = C[j];
        if (!Feasible()) {
            lp_type = INFEASIBLE;
            return;
        }
        while (true) {
            int r=0, c=0;
            double p = 0.0;
            for (int i = 0; i < n; i++) {
                if (A[m][i] > p)
                    p = A[m][c=i];
            }
            if (p < EPS) {
                for (int j = 0; j < n; j++)
                    if (nonbasic[j] < n)
                        soln[nonbasic[j]] = 0;
                for (int i = 0; i < m; i++)
                    if (basic[i] < n)
                        soln[basic[i]] = A[i][n];
                z = -A[m][n];
                lp_type = FEASIBLE;
                break;
            }
            p = INF;
            for (int i = 0; i < m; i++) {
                if (A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if (v < p) {p = v; r = i;}
                }
            }
            if (p == INF) {
                lp_type = UNBOUNDED;
                break;
            }
            Pivot(r,c);
        }
    }
private:
    void printa() {
        int i, j;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                printf("A[%d][%d] = %f\n", i, j, A[i][j]);
            }
        }
    }
    void Pivot(int r, int c) {
        //printf("pivot %d %d\n", r, c);
        //printa();
        swap(basic[r], nonbasic[c]);
        A[r][c] = 1 / A[r][c];
        for (int j = 0; j <= n; j++) {
            if (j != c)
                A[r][j] *= A[r][c];
        }
        for (int i = 0; i <= m; i++) {
            if (i != r) {
                for (int j = 0; j <= n; j++) {
                    if (j != c)
                        A[i][j] -= A[i][c] * A[r][j];
                }
                A[i][c] = -A[i][c] * A[r][c];
            }
        }
    }
    bool Feasible() {
        int r = 0, c = 0;
        while (true) {
            double p = INF;
            for (int i = 0; i < m; i++) 
                if (A[i][n] < p)
                    p = A[r=i][n];
            if (p > -EPS)
                return true;
            p = 0.0;
            for (int i = 0; i < n; i++)
                if (A[r][i] < p)
                    p = A[r][c=i];
            if (p > -EPS)
                return false;
            p = A[r][n] / A[r][c];
            for (int i = r+1; i < m; i++) {
                if (A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if (v < p) {
                        p = v;
                        r = i;
                    }
                }
            }
            Pivot(r,c);
        }
    }
};

int tt = 1, n, m;

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

```
\newpage

# optim/min_cost_flow.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct FlowEdge {
    int u, v;
    long long cap, cost, flow = 0;
    FlowEdge(int u, int v, long long cap, long long cost) : u(u), v(v), cap(cap), cost(cost) {}
};
struct MinCostFlow {
    vector<vector<int>> adj, cost, cap;
    vector<FlowEdge> edges;
    vector<pair<long long, long long>> ans;
    const long long INF = 1e14;
    int n, m = 0;
    int s, t;
    MinCostFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
    }
    void add_edge(int u, int v, long long cap_, long long cost_) {
        edges.emplace_back(u, v, cap_, cost_);
        edges.emplace_back(v, u, 0, -cost_);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    void shortest_paths(int v0, vector<long long>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id : adj[u]) {
                int v = edges[id].v;
                if (edges[id].cap > 0 && d[v] > d[u] + edges[id].cost) {
                    d[v] = d[u] + edges[id].cost;
                    p[v] = id;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    long long flow(long long k = -1) {
        if (k == -1) k = INF;
        long long flow = 0;
        long long cost = 0;
        vector<long long> d;
        vector<int> p;
        while (flow < k) {
            shortest_paths(s, d, p);
            if (d[t] == INF)
                break;
            // find max flow on that path
            long long f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, edges[p[cur]].cap);
                cur = edges[p[cur]].u;
            }
            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                edges[p[cur]].flow += f;
                edges[p[cur]^1].flow -= f;
                edges[p[cur]].cap -= f;
                edges[p[cur]^1].cap += f;
                cur = edges[p[cur]].u;
            }
            ans.push_back({flow, cost});
        }
        if (k < INF && flow < k)
            return -1;
        else
            return cost;
    }
};

int tt = 1, n, m, k;

// check long long
void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# optim/ternary_search.cpp
```cpp
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

```
\newpage

# optim/binary_search.cpp
```cpp
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

```
\newpage

# optim/max_flow.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Dinic's algorithm for max flow
struct FlowEdge {
    int u, v;
    long long cap, flow = 0;
    FlowEdge(int u, int v, long long cap) : u(u), v(v), cap(cap) {}
};
struct MaxFlow {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    MaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, long long cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].v] != -1)
                    continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int u, long long pushed) {
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
}; 

int tt = 1, n, m;

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

```
\newpage

# technique/sweepline.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

int tt = 1, n, m;

void solve() {
    cin >> n;
    vector<pll> a(n);
    for (auto& x : a)
        cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first < a[i].first) {
            pq.pop();
            // do stuff
        }
        pq.push({a[i].second, i});
        // do stuff
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

```
\newpage

# technique/two_pointers.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

int t, n;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && true/* */) {
            r++;
        }
        // do stuff
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}

```
\newpage

# struct/splay.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Splay Tree Node
template<typename T>
struct Node {
    Node *l, *r, *p;
    T v;
    size_t n;
    Node() : l(nullptr), r(nullptr), p(nullptr), v(0), n(1) {};
    Node(T v_) : l(nullptr), r(nullptr), p(nullptr), v(v_), n(1) {};
    Node(T v_, Node *l_, Node *r_) : l(l_), r(r_), p(nullptr), v(v_), n(1) {
        if (l != nullptr)
            l->p = this, n += l->n;
        if (r != nullptr)
            r->p = this, n += r->n;
    };
    Node(T v_, Node *l_, Node *r_, Node *p_) : l(l_), r(r_), p(p_), v(v_), n(1) {
        if (l != nullptr)
            l->p = this, n += l->n;
        if (r != nullptr)
            r->p = this, n += r->n;
    };
};
// Splay Tree
template<typename T>
struct SplayTree {
    Node<T>* root;
    const int CNT = 4;
    SplayTree() : root(nullptr) {};
private:
    void print_util(Node<T> *x, int s) { // for debugging
        if (x == nullptr)
            return;
        if (s != 0) {
            assert(x->p != nullptr);
            assert(x->p->l == x || x->p->r == x);
        }
        s += CNT;
        print_util(x->r, s);
        cout << endl;
        cout << string(s-CNT, ' ');
        cout << x->v << "[" << x->n << "]\n";
        print_util(x->l, s);
    }
    void update_n(Node<T> *x) {
        x->n = 1;
        if (x->l != nullptr)
            x->n += x->l->n;
        if (x->r != nullptr)
            x->n += x->r->n;
    }
public:
    void print() {
        assert(root->p == nullptr);
        print_util(root, 0);
    }
    void left_rotate(Node<T> *y) {
        Node<T> *x = y->r, *p = y->p, *B = x->l;
        // assert(x != nullptr);
        if (p) {
            if (p->r == y)
                p->r = x;
            else
                p->l = x;
        } else {
            // assert(root == y);
            root = x;
        }
        if (B) {
            B->p = y;
        }
        x->p = p;
        x->l = y;
        y->p = x;
        y->r = B;
        update_n(y);
        update_n(x);
    }
    void right_rotate(Node<T> *y) {
        Node<T> *x = y->l, *p = y->p, *B = x->r;
        // assert(x != nullptr);
        if (p) {
            if (p->r == y)
                p->r = x;
            else
                p->l = x;
        } else {
            // assert(root == y);
            root = x;
        }
        if (B) {
            B->p = y;
        }
        x->p = p;
        x->r = y;
        y->p = x;
        y->l = B;
        update_n(y);
        update_n(x);
    }
    void splay(Node<T> *x) { // splay a node
        while (x->p != nullptr) { // a single splay step
            Node<T> *y = x->p, *z = y->p;
            if (z == nullptr && y->l == x) { // zig
                right_rotate(y);
            } else if (z == nullptr && y->r == x) {
                left_rotate(y);
            } else if (z->l == y && y->r == x) { // zig-zag
                left_rotate(y);
                right_rotate(z);
            } else if (z->r == y && y->l == x) { // zig-zag
                right_rotate(y);
                left_rotate(z);
            } else if (z->l == y && y->l == x) { // zig-zig 
                right_rotate(z);
                right_rotate(y);
            } else if (z->r == y && y->r == x) { // zig-zig
                left_rotate(z);
                left_rotate(y);
            }
        }
        root = x;
    }
private:
    Node<T> *get_util(Node<T> *x, size_t index) {
        // Find the node with index in O(log n) time, assuming balanced
        // assert(0 <= index && index < x->n);
        size_t ls = 0;
        if (x->l != nullptr)
            ls = x->l->n;
        if (index < ls)
            return get_util(x->l, index);
        else if (index == ls)
            return x;
        else
            return get_util(x->r, index-ls-1);
    }
public:
    Node<T> *get(size_t index) {
        // assert(root != nullptr);
        return get_util(root, index);
    }
    void insert_left(Node<T> *x, T v) {
        x->l = new Node<T>(v, x->l, nullptr, x);
        update_n(x->l);
        update_n(x);
        splay(x->l);
    }
    void insert_right(Node<T> *x, T v) {
        x->r = new Node<T>(v, nullptr, x->r, x);
        update_n(x->r);
        update_n(x);
        splay(x->r);
    }
    void insert(T v) {
        
    }
};

int tt = 1, n, m, k;

// check long long
void solve() {
    using Node = Node<int>;
    SplayTree<int> st;
    Node *D = new Node(0);
    Node *E = new Node(2);
    Node *F = new Node(4);
    Node *G = new Node(6);
    Node *B = new Node(1, D, E);
    Node *C = new Node(5, F, G);
    Node *A = new Node(3, B, C);
    assert(A->l == B);
    assert(A->r == C);
    assert(B->p == A);
    assert(C->p == A);
    st.root = A;
    st.left_rotate(B);
    st.left_rotate(A);
    st.right_rotate(C);
    st.right_rotate(A);
    st.splay(D);
    st.print();
    st.insert_right(G, 7);
    st.print();
    st.splay(F);
    st.insert_left(D, -1);
    st.print();
    printf("Finished");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# struct/test.cpp
```cpp
import x


```
\newpage

# struct/trie.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const int K = 26;
struct Vertex {
    vector<int> nxt;
    bool leaf = false;
    Vertex() { nxt.assign(K, -1); }
};
vector<Vertex> trie(1);
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}

int tt = 1, n, m, k;

// check long long
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

```
\newpage

# struct/segtree_range_add.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
struct MaxInt {
    using T = long long;
    const T e = LLONG_MIN;
    T f(T a, T b) const { return max(a, b); }
};
struct MinInt {
    using T = long long;
    const T e = LLONG_MAX;
    T f(T a, T b) const { return min(a, b); }
};
template <class B>
struct SegTree : public B {
    using T = typename B::T;
    int n;
    vector<T> tree;
    vector<T> add;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    void _push(int v) {
        tree[v*2  ] += add[v];
        tree[v*2+1] += add[v];
        add[v*2  ] += add[v];
        add[v*2+1] += add[v];
        add[v] = 0;
    }
    void _update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] += val;
            add[v] += val;
            return;
        }
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    T _query(int v, int tl, int tr, int l, int r) {
        if (l > r || tr < l || tl > r)
            return B::e;
        if (tr <= r && tl >= l)
            return tree[v];
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        return B::f(_query(v*2, tl, tmid, l, min(r, tmid)),
                    _query(v*2+1, tmid+1, tr, max(l, tmid+1), r));
    }
    T _get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return tree[v];
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, B::e);
        add.assign(4*n, 0);
        vector<T> a(n, B::e);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, B::e);
        add.assign(4*n, 0);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(T val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
};

int tt = 1, n, m;

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

```
\newpage

# struct/treap.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T>
class Node {
    T key;
    int prior;
    Node<T> *l, *r;
    Node() : key(0), prior(0), l(nullptr), r(nullptr) {}
    Node(T k, int p) : key(k), prior(p), l(nullptr), r(nullptr) {}
private:
    using Node_t = Node *;
public:
    friend bool operator > (const Node& a, const Node& b) { 
        return a.key > b.key;
    }
    friend bool operator < (const Node& a, const Node& b) {
        return a.key < b.key;
    }
    friend bool operator == (const Node& a, const Node& b) {
        return a.key == b.key;
    }
    friend ostream& operator << (ostream& o, const Node& a) {
        o << a.key; return o;
    }
    static void split(Node_t t, T key, Node_t low, Node_t hi) {
        if (t == nullptr) low = hi = nullptr;
        else if (key < t->key)
            split(t->l, key, low, t->l), hi = t;
        else
            split(t->r, key, t->r, hi), low = t;
    }
    static void insert(Node_t& t, Node_t it) {
        if (t == nullptr)
            t = it;
        else if (it->prior > t->prior)
            split(t, it->key, it->l, it->r), t = it;
        else
            insert(it->key < t->key ? t->l : t->r, it);
    }
    static void merge(Node_t& t, Node_t l, Node_t r) {
        if (!l || !r)
            t = l ? l : r;
        else if (l->prior > r->prior)
            merge(l->r, l->r, r), t = l;
        else
            merge(r->l, l, r->l), t = r;
    }
    static void erase(Node_t& t, T key) {
        if (t->key == key) {
            Node_t th = t;
            merge(t, t->l, t->r);
            delete th;
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }
    static Node_t unite(Node_t l, Node_t r) {
        if (!l || !r) return l ? l : r;
        if (l->prior < r->prior) swap(l, r);
        Node_t lt, rt;
        split(r, l->key, lt, rt);
        l->l = unite(l->l, lt);
        l->r = unite(l->r, rt);
        return l;
    }
};
template <typename T>
class Treap {
    Node<T> *root;
    Treap() { root = nullptr; }
    Treap(T d, int p) { root = new Node<T> (d, p); }
    Treap(Node<T> *n) { root = n; }
public:
    explicit operator Node<T>() { return *root; }
    // Overload operator
    friend bool operator < (const Treap& a, const Treap& b) {
        return *a.root < *b.root;
    }
    friend bool operator > (const Treap& a, const Treap& b) {
        return *a.root > *b.root;
    }
    friend bool operator == (const Treap& a, const Treap& b) {
        return *a.root == *b.root;
    }
    friend ostream& operator << (ostream& o, const Treap& a) {
        o << *a.root; return o;
    }
    // Access variables
    T key() { assert(root != nullptr); return root->key; }
    int priority () { assert(root != nullptr); return root->prior; }
    Treap l() const { assert(root != nullptr); return Treap(root->l); }
    Treap r() const { assert(root != nullptr); return Treap(root->r); }
    // Functions
    Treap split(int key, Treap& low, Treap& hi) {
        Node<T>::split(root, key, low.root, hi.root);
        return *this;
    }
    Treap insert(Treap& it) {
        Node<T>::insert(root, it.root);
        return *this;
    }
    Treap merge(Treap& l, Treap& r) {
        Node<T>::merge(root, l.root, r.root);
        return *this;
    }
    Treap erase(T key) {
        Node<T>::erase(root, key);
        return *this;
    }
    static Treap unite(Treap& l, Treap& r) {
        Node<T> *res = Node<T>::unite(l.root, r.root);
        return Treap(res);
    }
};

int t = 1, n, m, k, q;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# struct/rmq.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Range Minimum Query with sparse table
// O(nlogn) preprocessing, O(1) query
struct MaxInt {
    using T = long long;
    const T e = LLONG_MIN;
    T f(T a, T b) const { return max(a, b); }
};
struct MinInt {
    using T = long long;
    const T e = LLONG_MAX;
    T f(T a, T b) const { return min(a, b); }
};
template <class B>
class RMQ : public B {
    using T = typename B::T;
    int n, lim;
    vector<vector<T>> spt;
private:
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = B::f(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a) : n(a.size()), lim(floor(log2(n)+1)) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = B::f(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};

int tt = 1, n, m;

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

```
\newpage

# struct/segtree_range_assign.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

/* Segment tree with range assignment query and range sum query */
template <typename T>
struct SegTree {
    int n;
    vector<T> tree;
    vector<bool> mark;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            mark[v] = true;
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = 0;
    }
    void _push(int v) {
        if (mark[v]) {
            tree[v*2] = tree[v*2+1] = tree[v];
            mark[v*2] = mark[v*2+1] = true;
            mark[v] = false;
        }
    }
    void _update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] = val;
            mark[v] = true;
            return;
        }
        _push(v);
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
    }
    T _query(int v, int tl, int tr, int l, int r) const {
        if (l > r || tr < l || tl > r)
            return 0;
        if (mark[v] && tr >= r && tl <= l)
            return tree[v] * (r-l+1);
        int tmid = tl + (tr - tl) / 2;
        return _query(v*2, tl, tmid, l, min(r, tmid)) +
               _query(v*2+1, tmid+1, tr, max(l, tmid+1), r);
    }
    T _get(int v, int tl, int tr, int pos) const {
        if (tl == tr || mark[v])
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        vector<T> a(n, 0);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(T val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
};

int tt = 1, n, m;

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

```
\newpage

# struct/segtree_2d.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct SumInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const { return a + b; }
};
struct MaxInt {
    using T = long long;
    const T e = LLONG_MIN;
    T f(T a, T b) const { return max(a, b); }
};
struct MinInt {
    using T = long long;
    const T e = LLONG_MAX;
    T f(T a, T b) const { return min(a, b); }
};
template <class B>
struct SegTree : public B {
    using T = typename B::T;
    int n, m;
    vector<vector<T>> tree;
private:
    void _build_y(const vector<vector<T>>& a, int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                tree[vx][vy] = a[lx][ly];
            else
                tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];
        } else {
            int my = (ly + ry) / 2;
            _build_y(a, vx, lx, rx, vy*2, ly, my);
            _build_y(a, vx, lx, rx, vy*2+1, my+1, ry);
            tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
        }
    }
    void _build_x(const vector<vector<T>>& a, int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(a, vx*2, lx, mx);
            build_x(a, vx*2+1, mx+1, rx);
        }
        _build_y(a, vx, lx, rx, 1, 0, m-1);
    }
    T _query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) 
            return 0;
        if (ly == tly && try_ == ry)
            return tree[vx][vy];
        int tmy = (tly + try_) / 2;
        return B::f(_query_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)),
                    _query_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
    }
    T _query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx)
            return 0;
        if (lx == tlx && trx == rx)
            return _query_y(vx, 1, 0, m-1, ly, ry);
        int tmx = (tlx + trx) / 2;
        return B::f(_query_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry),
                    _query_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
    }
    void _update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
        if (ly == ry) {
            if (lx == rx)
                tree[vx][vy] = new_val;
            else
                tree[vx][vy] = B::f(tree[vx*2][vy], tree[vx*2+1][vy]);
        } else {
            int my = (ly + ry) / 2;
            if (y <= my)
                _update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
            else
                _update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
            tree[vx][vy] = B::f(tree[vx][vy*2], tree[vx][vy*2+1]);
        }
    }
    void _update_x(int vx, int lx, int rx, int x, int y, int new_val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                _update_x(vx*2, lx, mx, x, y, new_val);
            else
                _update_x(vx*2+1, mx+1, rx, x, y, new_val);
        }
        _update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
    }
public:
    SegTree(int n_, int m_) : n(n_), m(m_) {
        tree.assign(4*n, vector<T>(4*m, B::e));
        vector<T> a(n, vector<T>(m, B::e));
        _build_y(a, 1, 0, n-1, 1, 0, m-1);
    }
    SegTree(const vector<vector<T>>& a) : n(a.size()), m(a[0].size()) {
        tree.assign(4*n, vector<T>(4*m, B::e));
        _build_y(a, 1, 0, n-1, 1, 0, m-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)              { _build(a, 1, 0, n-1); }
    void update(T val, int x, int y)            { _update_x(1, 0, n-1, x, y, val); }
    T query(int lx, int rx, int ly, int ry)     { return _query_x(1, 0, n-1, lx, rx, ly, ry); }
};


int tt = 1, n, m, k;

// check long long
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

```
\newpage

# struct/fenwick.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;
    FenwickTree(int n_) : n(n_) { bit.assign(n, 0); }
    FenwickTree(vector<int>& a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; ++i)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (int i = r; i >= 0; i = (i & (i+1)) - 1)
            ret += bit[i];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    void add(int idx, int delta) {
        for (int i = idx; i < n; i = i | (i + 1))
            bit[i] += delta;
    }
};

int t = 1, n, m, k, q;

```
\newpage

# struct/segtree.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
struct SumInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const { return a + b; }
};
struct MaxInt {
    using T = long long;
    const T e = LLONG_MIN;
    T f(T a, T b) const { return max(a, b); }
};
struct MinInt {
    using T = long long;
    const T e = LLONG_MAX;
    T f(T a, T b) const { return min(a, b); }
};
struct GCDInt {
    using T = long long;
    const T e = 0;
    T f(T a, T b) const {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        return gcd(a, b);
    }
};
template <class B>
struct SegTree : public B {
    using T = typename B::T;
    int n;
    vector<T> tree;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _build(a, v*2, tl, tmid);
        _build(a, v*2+1, tmid+1, tr);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    void _update(int v, int tl, int tr, int pos, T val) {
        if (tl > tr || pos > tr || pos < tl)
            return;
        if (pos == tl && pos == tr) {
            tree[v] = val;
            return;
        }
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, pos, val);
        _update(v*2+1, tmid+1, tr, pos, val);
        tree[v] = B::f(tree[v*2], tree[v*2+1]);
    }
    T _query(int v, int tl, int tr, int l, int r) const {
        if (l > r || tr < l || tl > r)
            return B::e;
        if (tr <= r && tl >= l)
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        return B::f(_query(v*2, tl, tmid, l, min(r, tmid)),
                    _query(v*2+1, tmid+1, tr, max(l, tmid+1), r));
    }
    T _get(int v, int tl, int tr, int pos) const {
        if (tl == tr)
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(int n_) : n(n_) {
        tree.assign(4*n, B::e);
        vector<T> a(n, B::e);
        _build(a, 1, 0, n-1);
    }
    SegTree(const vector<T>& a) : n(a.size()) {
        tree.assign(4*n, B::e);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, const SegTree& st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void build(const vector<T>& a)   { _build(a, 1, 0, n-1); }
    void update(T val, int pos)      { _update(1, 0, n-1, pos, val); }
    T query(int l, int r)            { return _query(1, 0, n-1, l, r); }
    T get(int pos)                   { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)            { return get(pos); }
};

int tt = 1, n, m;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# combinatorics/stirling.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int MOD = 7340033;
const int ROOT = 5;
const int ROOT_1 = 4404020;
const int ROOT_PW = 1 << 20;

void ntt(vector<ll>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? ROOT_1 : ROOT;
        for (int i = len; i < ROOT_PW; i <<= 1)
            wlen = (1LL * wlen * wlen % MOD);

        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (1LL * a[i+j+len/2] * w % MOD);
                a[i+j] = u + v < MOD ? u + v : u + v - MOD;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (1LL * w * wlen % MOD);
            }
        }
    }

    if (invert) {
        ll n_1 = inverse(n, MOD);
        for (ll& x : a)
            x = (1LL * x * n_1 % MOD);
    }
}
vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) 
        N <<= 1;
    fa.resize(N);
    fb.resize(N);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] = (fa[i] * fb[i]) % MOD;
    ntt(fa, true);

    vector<int> result(N);
    for (int i = 0; i < N; i++)
        result[i] = (int)fa[i];
    return result;
}

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

```
\newpage

# string/aho_corasick.cpp
```cpp

```
\newpage

# string/kmp.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Knuth-Morris-Pratt algorithm for finding the occurrence of a certain word 
 * from some text.
 */
int kmp_search(string s, string w) {
    int m = s.size(), n = w.size();
    if (n == 0) return 0;

    // compute table using two pointers
    int t[n];
    t[0] = -1; // must restart all
    for (int p = 1, q = 0; p < n; ++p, ++q) {
        if (w[p] == w[q]) t[p] = t[q];
        else {
            t[p] = q;
            q = t[q];
            while (q >= 0 && w[p] != w[q]) q = t[q];
        }
    }

    // search
    for (int i = 0, j = 0; i < m; ) {
        if (w[j] == s[i]) {
            ++i; ++j;
            if (j == n) return i-j; // found
        } else {
            assert(j < n);
            j = t[j];
            if (j < 0) { // start again
                ++i; ++j;
            }
        }
    }
    return -1;
}

```
\newpage

# geometry/geometry.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const double EPS = 1e-9;

struct pt {
    double x, y;
    pt() : x(0.0), y(0.0) {}
    pt(double x, double y) : x(x), y(y) {}
    friend ostream& operator<<(ostream& os, const pt& a) {
        return os << "(" << a.x << "," << a.y << ")";
    }
    friend istream& operator>>(istream& is, pt& a) {
        return is >> a.x >> a.y;
    }
    pt& operator+=(const pt& a) {
        x += a.x;
        y += a.y;
        return *this;
    }
    pt& operator-=(const pt& a) {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    pt& operator*=(const double c) {
        x *= c;
        y *= c;
        return *this;
    }
    pt& operator/=(const double c) {
        x /= c;
        y /= c;
        return *this;
    }
    friend pt operator+(const pt& a, const pt& b) {
        return pt(a) += b;
    }
    friend pt operator-(const pt& a, const pt& b) {
        return pt(a) -= b;
    }
    friend pt operator*(const pt& a, const double c) {
        return pt(a) *= c;
    }
    friend pt operator*(const double c, const pt& a) {
        return pt(a) *= c;
    }
    friend pt operator/(const pt& a, const double c) {
        return pt(a) /= c;
    }
    friend double dot(pt a, pt b) {
        return a.x * b.x + a.y * b.y;
    }
    friend double cross(pt a, pt b) {
        return a.x * b.y - a.y * b.x;
    }
    friend double len(pt a) {
        double s = a.x * a.x + a.y * a.y;
        return sqrt(s);
    }
    friend double dist(pt a, pt b) {
        return len(a - b);
    }
    friend pt intersect(pt a1, pt d1, pt a2, pt d2) {
        // intersection between a1 + td1 and a2 + td2
        return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
    }
    friend double polygon_area(const vector<pt>& fig) {
        double res = 0;
        for (int i = 0; i < (int)fig.size(); i++) {
            pt p = i ? fig[i - 1] : fig.back();
            pt q = fig[i];
            res += (p.x - q.x) * (p.y + q.y);
        }
        return fabs(res) / 2;
    }
};
struct line {
    double a, b, c;
    line() : a(0.0), b(0.0), c(0.0) {}
    line(double a, double b, double c) : a(a), b(b), c(c) {}
    friend ostream& operator<<(ostream& os, const line& l) {
        return os << l.a << " " << l.b << " " << l.c;
    }
    friend line offset(line l, pt a, bool invert=false) {
        // invert = false then (0,0) -> a, true then a -> (0,0)
        if (invert)
            l.c += l.a * a.x + l.b * a.y;
        else
            l.c -= l.a * a.x + l.b * a.y;
        return l;
    }
};
struct circle {
    pt c;
    double r;
    circle() : r(0.0) {}
    circle(double r) : r(r) {}
    circle(pt c, double r) : c(c), r(r) {}
    friend ostream& operator<<(ostream& os, const circle& a) {
        return os << a.c << " " << a.r;
    }
    friend istream& operator>>(istream& is, circle& a) {
        return is >> a.c >> a.r;
    }
    void line_circle_intersection(circle a, line l, vector<pt>& ans) {
        l = offset(l, a.c, true);
    }
    void tangent_circle(circle a, circle b, vector<line>& ans) {
        auto tangent_line = [&](pt c, double r1, double r2) {
            double r = r2 - r1;
            double z = c.x * c.x + c.y * c.y;
            double d = z - r * r;
            if (d < -EPS) return;
            d = sqrt(abs(d));
            line l;
            l.a = (c.x * r + c.y * d) / z;
            l.b = (c.y * r - c.x * d) / z;
            l.c = r1; 
            l = offset(l, a.c);
            ans.push_back(l);
        };
        for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 1; j += 2)
                tangent_line(b.c - a.c, a.r * i, b.r * j);
    }
};

void solve() {
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# geometry/basic.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define pt  complex<double>

pt add(pt a, pt b)                  { return a + b; }
pt mult(pt a, double r)             { return r * a; }
double dot(pt a, pt b)              { return (conj(a) * b).real(); }
double cross(pt a, pt b)            { return (conj(a) * b).imag(); }
double squared_dist(pt a, pt b)     { return norm(a - b); }
double dist(pt a, pt b)             { return abs(a - b); }
double angle(pt a, pt b)            { return arg(b - a); }
double slope(pt a, pt b)            { return tan(arg(b - a)); }
pt po_to_cart(pt p)                 { return polar(p.real(), p.imag()); }
pt cart_to_po(pt a)                 { return pt(abs(a), arg(a)); }
pt rotate(pt a, double theta)       { return a * polar(1.0, theta); }
pt rotate(pt a, pt p, double theta) { return (a-p) * polar(1.0, theta) + p; }
pt project(pt p, pt v)              { return v * dot(p, v) / norm(v); }
pt project(pt p, pt a, pt b)        { return a + project(p-a, b-a); }
pt reflect(pt p, pt a, pt b)        { return a + conj((p-a) / (b-a)) * (b-a); }
pt angle(pt a, pt b, pt c) { 
    return abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI));
}
pt intersection(pt a, pt b, pt p, pt q) {
    double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
    return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

int tt = 1, n, m;
void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# geometry/convex_hull.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define pt  array<double,2>

// Convex hull using Graham scan
// Should not contain dulicate points
bool cw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) <= 0;
}
bool ccw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) > 0;
}
vector<pt> convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;
    sort(a.begin(), a.end());
    pt p1 = a[0], p2 = a.back();
    vector<pt> u, d;
    u.push_back(p1);
    d.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (u.size() >= 2 && !cw(u[u.size()-2], u[u.size()-1], a[i]))
                u.pop_back();
            u.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (d.size() >= 2 && !ccw(d[d.size()-2], d[d.size()-1], a[i]))
                d.pop_back();
            d.push_back(a[i]);
        }
    }
    vector<pt> res;
    for (int i = 0; i < (int)u.size(); i++)
        res.push_back(u[i]);
    for (int i = d.size() - 2; i > 0; i--)
        res.push_back(d[i]);
    return res;
}

int tt = 1, n, m;

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


```
\newpage

# reference/dijkstra.cpp
```cpp
/**
 *  Reference solution using Dijkstra's Algorithm and Union Find
 *  Codeforces 1253 F "Cheap Robot"
 *  https://codeforces.com/contest/1253/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

const int64_t INF = 1e18;
int t = 1, n, m, k, q;
vector<vector<pll>> adj;
vector<ll> dist, res;
vector<int> parent, sz, query;
vector<vector<int>> token;
 
int find_set(int v) {
    if (parent[v] == v)
        return v;
    return find_set(parent[v]);
}
bool union_sets(int v, int u, ll cap) {
    u = find_set(u), v = find_set(v);
    if (u == v) return false;
    if (sz[v] < sz[u]) swap(u, v);
    for (int tk : token[u]) { // Move token to the new parent
        int other = tk^1;
        int i = tk/2;
        if (find_set(query[other]) == v)
            res[i] = cap;
        token[v].push_back(tk);
    }
    token[u] = vector<int> (0);
 
    sz[v] += sz[u];
    parent[u] = v;
    return true;
}
 
void solve() {
    cin >> n >> m >> k >> q;
    // Initialize vectors
    adj.resize(n);
    token.resize(n);
    dist.assign(n, INF);
    parent.assign(n, 0);
    sz.assign(n, 0);
    query.assign(2*q, 0);
    res.assign(q, 0);
    // Read graph
    vector<array<ll,3>> edges;
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    }
    // Multi-soure Dijkstra's algorithm
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int v = 0; v < k; ++v) {
        pq.push({0, v});
        dist[v] = 0;
    }
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (d != dist[v])
            continue;
        for (auto e : adj[v]) {
            ll u = e.first, w = e.second;
            if (dist[v]+w < dist[u]) {
                dist[u] = dist[v]+w;
                pq.push({dist[u], u});
            }
        }
    }
    // Compute the new weight of the edges
    for (auto& e : edges)
        e[0] += dist[e[1]] + dist[e[2]];
    sort(edges.begin(), edges.end());
    // Read query
    for (int i = 0; i < q; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        --n1, --n2;
        query[2*i] = n1, query[2*i+1] = n2;
        token[n1].push_back(2*i);
        token[n2].push_back(2*i+1);
    }
    // Union Find
    for (int v = 0; v < n; ++v) {
        parent[v] = v;
        sz[v] = 1;
    }
    for (auto e : edges)
        union_sets(e[2], e[1], e[0]);
    for (int i = 0; i < q; ++i)
        cout << res[i] << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/scc.cpp
```cpp
/**
 *  Reference solution using DFS to find strongly connected components
 *  Codeforces 999 E "Reachability from the Capital"
 *  https://codeforces.com/contest/999/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj, adj_rev;
vector<bool> vis;
vector<int> order, components;
vector<vector<int>> res;

void dfs1(int v) {
    vis[v] = true;
    for (int u : adj[v])
        if (!vis[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    vis[v] = true;
    components.push_back(v);
    for (int u : adj_rev[v])
        if (!vis[u])
            dfs2(u);
}

// check long long
void solve() {
    int s;
    cin >> n >> m >> s;
    s--;
    adj.assign(n, vector<int>());
    adj_rev.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    order.clear();
    components.clear();
    vis.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs1(i);
    vis.assign(n, 0);
    reverse(order.begin(), order.end());
    vector<int> parent(n);
    int N = 0;
    for (int v : order) {
        if (!vis[v]) {
            dfs2(v);
            for (int v : components)
                parent[v] = N;
            N++;
            components.clear();
        }
    }
    vector<unordered_set<int>> adj_contract(N, unordered_set<int>());
    for (int v = 0; v < n; v++) {
        for (int u : adj[v])
            if (parent[u] != parent[v])
                adj_contract[parent[u]].insert(parent[v]);
    }
    int ans = 0;
    for (int v = 0; v < N; v++) {
        if (adj_contract[v].size() == 0 && v != parent[s])
            ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/simplex.cpp
```cpp
/**
 *  Reference solution using simplex algorithm for linear programming
 *  15-451 Fall 2021 Homework 6 Programming "A Cop and a Robber"
 *  https://www.cs.cmu.edu/~15451-f21/hws/hw6.pdf
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Simplex algorithm for solving linear programming
// maximize <c, x>
// subject to Ax <= b
// m constraints, n variables
struct Simplex {
public:
    int m, n;
    vector<vector<double>> A;
    vector<int> basic;                  // size m.  indices of basic vars
    vector<int> nonbasic;               // size n.  indices of non-basic vars
    vector<double> soln;
    double z;                           // return value of the objective function.
    int lp_type;                        // for return.  1 if feasible, 0 if not feasible, -1 if unbounded
    const double INF = 1e100;
    const double EPS = 1e-9;
    const static int FEASIBLE = 1;
    const static int INFEASIBLE = 0;
    const static int UNBOUNDED = -1;
    Simplex(int m0, int n0, vector<vector<double>>& A0,
            vector<double>& B, vector<double>& C) :
            m(m0),
            n(n0),
            A(m0+1) {
        basic.resize(m0);
        nonbasic.resize(n0);
        soln.resize(n);
        for (int i = 0; i < A.size(); i++) {
            A[i].resize(n+1);
        }
        for (int j = 0; j < m; j++)
            basic[j] = n+j;
        for (int i = 0; i < n; i++)
            nonbasic[i] = i;
        for (int i = 0; i < m; i++) {
            A[i][n] = B[i];
            for (int j = 0; j < n; j++)
                A[i][j] = A0[i][j];
        }
        for (int j = 0; j < n; j++)
            A[m][j] = C[j];
        if (!Feasible()) {
            lp_type = INFEASIBLE;
            return;
        }
        while (true) {
            int r=0, c=0;
            double p = 0.0;
            for (int i = 0; i < n; i++) {
                if (A[m][i] > p)
                    p = A[m][c=i];
            }
            if (p < EPS) {
                for (int j = 0; j < n; j++)
                    if (nonbasic[j] < n)
                        soln[nonbasic[j]] = 0;
                for (int i = 0; i < m; i++)
                    if (basic[i] < n)
                        soln[basic[i]] = A[i][n];
                z = -A[m][n];
                lp_type = FEASIBLE;
                break;
            }
            p = INF;
            for (int i = 0; i < m; i++) {
                if (A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if (v < p) {p = v; r = i;}
                }
            }
            if (p == INF) {
                lp_type = UNBOUNDED;
                break;
            }
            Pivot(r,c);
        }
    }
private:
    void printa() {
        int i, j;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                printf("A[%d][%d] = %f\n", i, j, A[i][j]);
            }
        }
    }
    void Pivot(int r, int c) {
        //printf("pivot %d %d\n", r, c);
        //printa();
        swap(basic[r], nonbasic[c]);
        A[r][c] = 1 / A[r][c];
        for (int j = 0; j <= n; j++) {
            if (j != c)
                A[r][j] *= A[r][c];
        }
        for (int i = 0; i <= m; i++) {
            if (i != r) {
                for (int j = 0; j <= n; j++) {
                    if (j != c)
                        A[i][j] -= A[i][c] * A[r][j];
                }
                A[i][c] = -A[i][c] * A[r][c];
            }
        }
    }
    bool Feasible() {
        int r = 0, c = 0;
        while (true) {
            double p = INF;
            for (int i = 0; i < m; i++) 
                if (A[i][n] < p)
                    p = A[r=i][n];
            if (p > -EPS)
                return true;
            p = 0.0;
            for (int i = 0; i < n; i++)
                if (A[r][i] < p)
                    p = A[r][c=i];
            if (p > -EPS)
                return false;
            p = A[r][n] / A[r][c];
            for (int i = r+1; i < m; i++) {
                if (A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if (v < p) {
                        p = v;
                        r = i;
                    }
                }
            }
            Pivot(r,c);
        }
    }
};

int tt = 1, n, m, z;
int d[305][305], win[305][305];

void solve() {
    int dcop, drob;
    cin >> n >> m >> drob >> dcop;
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d[u][v] = 1;
        d[v][u] = 1;
    }
    // first compute shortest distance using Floyd-Warshall
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool can = false;
            for (int k = 0; k < n; k++) {
                if (d[i][k] > drob)
                    continue;
                if (d[j][k] > dcop)
                    can = true;
            }
            win[i][j] = can;
        }
    }
    vector<vector<double>> A(n+2, vector<double>(n+1, 0.0));
    vector<double> b(n+2, 0.0);
    vector<double> c(n+1, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (win[j][i])
                A[i][j] = -1.0;
        }
        A[i][n] = 1.0;
    }
    for (int j = 0; j < n; j++) {
        A[n][j] = -1.0;
        A[n+1][j] = 1.0;
    }
    b[n] = -1.0;
    b[n+1] = 1.0;
    c[n] = 1.0;
    Simplex solver = Simplex(n+2, n+1, A, b, c);
    cout << fixed << setprecision(10) << solver.soln[n] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/sos_inv.cpp
```cpp
/**
 *  Reference solution using inverse sum over subsets dp
 *  Codeforces 1620 G "Subsequences Galore"
 *  https://codeforces.com/contest/1620/problem/G
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int(v_ % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

//const int MOD = 1e9+7;
const int MOD = 998244353;
using num = ModNum<MOD>;
int tt = 1, n, m;

template<class T_in, class T_out>
vector<T_out> inverse_sum_over_subsets(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i];
    for (int i = 0; i < n; i++)
        for (int base = 0; base < (1 << n); base += (1 << (i+1)))
            for (int mask = base; mask < base + (1 << i); mask++)
                f[mask + (1 << i)] -= f[mask];
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) % 2 == 0)
            f[mask] = 0-f[mask];
    }
    return f;

}

void solve() {
    cin >> n;
    vector<array<int,26>> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int j = 0;
        array<int,26> cnt = {};
        for (char c : s)
            cnt[c-'a']++;
        a.push_back(cnt);
    }
    vector<num> b(1 << n, 0);
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> mins(26, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int c = 0; c < 26; c++) {
                    mins[c] = min(mins[c], a[i][c]);
                }
            }
        }
        b[mask] = 1;
        for (int c = 0; c < 26; c++) {
            b[mask] *= num(mins[c] + 1);
        }
    }

    vector<num> f = inverse_sum_over_subsets<num, num>(b);

    ll ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int k = __builtin_popcount(mask), sm = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                sm += (i+1);
        ans ^= (ll)f[mask].v * k * sm;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}

```
\newpage

# reference/lca.cpp
```cpp
/**
 *  Reference solution using lowest common ancestor
 *  The problem directly asks if one node is the ancestor of the other.
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

// Lowest common ancestor with binary lifting
// O(n log n) build and O(log n) query
// The graph needs to be undirected
struct LCA {
    int n, lim;
    int timer = 0;
    vector<vector<int>> anc;
    vector<vector<int>> adj;
    vector<int> tin, tout;
private:
    void dfs(int v, int p) {
        tin[v] = ++timer;
        anc[v][0] = p;
        for (int i = 1; i <= lim; ++i)
            anc[v][i] = anc[anc[v][i-1]][i-1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    void print() {
        cout << "tin\n";
        for (int i = 0; i < n; i++)
            cout << tin[i] << " \n"[i+1==n];
        cout << "tout\n";
        for (int i = 0; i < n; i++)
            cout << tout[i] << " \n"[i+1==n];
        cout << "anc\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= lim; j++)
                cout << anc[i][j] << " \n"[j==lim];
        }

    }
public:
    LCA(int n_) : n(n_), lim(ceil(log(n_))) {
        tin.assign(n, 0);
        tout.assign(n, 0);
        adj.resize(n);
        anc.assign(n, vector<int>(lim+1, 0));
    }
    void init(int root = 0) {
        dfs(root, root);
    }
    int query(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = lim; i >= 0; --i) {
            if (!is_ancestor(anc[u][i], v))
                u = anc[u][i];
        }
        return anc[u][0];
    }
};

int tt = 1, n, m, q;

void solve() {
    cin >> n >> q;
    LCA G(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.adj[u].push_back(v);
        G.adj[v].push_back(u);
    }
    G.init();
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int x = G.query(u, v);
        cout << (x == u ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/sos.cpp
```cpp
/**
 *  Reference solution using sum over subsets dp
 *  Codeforces 165 E "Compatible Numbers"
 *  https://codeforces.com/contest/165/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int res[8000001];

template<class T_in, class T_out>
vector<T_out> sum_over_subsets(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i], res[i] = i;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) {
                f[mask] += f[mask^(1<<i)];
                if (f[mask^(1<<i)] > 0)
                    res[mask] = res[mask^(1<<i)];
            }
        }
    }
    return f;
}

// check long long
void solve() {
    cin >> m;
    vector<int> a(m);
    n = ceil(log2(4000001));
    vector<int> cnt(1 << n, 0);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> f = sum_over_subsets<int,int>(cnt);
    for (int i = 0; i < m; i++) {
        int inv_mask = (~a[i])&((1<<n)-1);
        if (f[inv_mask] == 0)
            cout << "-1";
        else
            cout << res[inv_mask];
        cout << " \n"[i+1==m];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/min_cost_flow.cpp
```cpp
/**
 *  Reference solution using min cost flow
 *  Codeforces 1307 G "Cow and Exercise"
 *  https://codeforces.com/contest/1307/problem/G
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct FlowEdge {
    int u, v;
    long long cap, cost, flow = 0;
    FlowEdge(int u, int v, long long cap, long long cost) : u(u), v(v), cap(cap), cost(cost) {}
};
struct MinCostFlow {
    vector<vector<int>> adj, cost, cap;
    vector<FlowEdge> edges;
    vector<pii> ans;
    const long long INF = 1e14;
    int n, m = 0;
    int s, t;
    long long k;
    MinCostFlow(int n, long long k, int s, int t) : n(n), k(k), s(s), t(t) {
        adj.assign(n, vector<int>());
    }
    void add_edge(int u, int v, long long cap_, long long cost_) {
        edges.emplace_back(u, v, cap_, cost_);
        edges.emplace_back(v, u, 0, -cost_);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    void shortest_paths(int v0, vector<long long>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id : adj[u]) {
                int v = edges[id].v;
                if (edges[id].cap > 0 && d[v] > d[u] + edges[id].cost) {
                    d[v] = d[u] + edges[id].cost;
                    p[v] = id;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    long long flow() {
        long long flow = 0;
        long long cost = 0;
        vector<long long> d;
        vector<int> p;
        while (flow < k) {
            shortest_paths(s, d, p);
            if (d[t] == INF)
                break;
            // find max flow on that path
            long long f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, edges[p[cur]].cap);
                cur = edges[p[cur]].u;
            }
            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                edges[p[cur]].cap -= f;
                edges[p[cur]^1].cap += f;
                cur = edges[p[cur]].u;
            }
            ans.push_back({flow, cost});
        }
        if (flow < k)
            return -1;
        else
            return cost;
    }
};

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    MinCostFlow G(n, (int)1e9, 0, n-1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G.add_edge(u, v, 1, w);
    }
    G.flow();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        double res = 1e14;
        for (auto& p : G.ans) {
            res = min(res, (double)(p.second + x)/p.first);
        }
        cout << fixed << setprecision(10) << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/fft.cpp
```cpp
/**
 *  Reference solution using fast Fourier transform (FFT)
 *  Codeforces 827 E "Rusty String"
 *  https://codeforces.com/contest/827/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) 
        N <<= 1;
    fa.resize(N);
    fb.resize(N);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(N);
    for (int i = 0; i < N; i++)
        result[i] = round(fa[i].real());
    return result;
}

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') {
            a[i] = 1;
        }
        if (s[i] == 'K') {
            b[n-1-i] = 1;
        }
    }
    vector<int> c = multiply(a, b);
    vector<int> sieve(n+1, 0);
    for (int i = 0; i < c.size(); i++)
        if (c[i])
            sieve[abs(i-n+1)] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (sieve[j]) {
                sieve[i] = 1;
                break;
            }
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!sieve[i]) {
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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

```
\newpage

# reference/min_cost_max_flow.cpp
```cpp
/**
 *  Reference solution using min cost max flow
 *  Codeforces 863 F "Almost Permutation"
 *  https://codeforces.com/contest/863/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

struct FlowEdge {
    int u, v;
    long long cap, cost, flow = 0;
    FlowEdge(int u, int v, long long cap, long long cost) : u(u), v(v), cap(cap), cost(cost) {}
};
struct MinCostFlow {
    vector<vector<int>> adj, cost, cap;
    vector<FlowEdge> edges;
    //vector<pii> ans;
    const long long INF = 1e14;
    int n, m = 0;
    int s, t;
    long long k;
    MinCostFlow(int n, long long k, int s, int t) : n(n), k(k), s(s), t(t) {
        adj.assign(n, vector<int>());
    }
    void add_edge(int u, int v, long long cap_, long long cost_) {
        edges.emplace_back(u, v, cap_, cost_);
        edges.emplace_back(v, u, 0, -cost_);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    void shortest_paths(int v0, vector<long long>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id : adj[u]) {
                int v = edges[id].v;
                if (edges[id].cap > 0 && d[v] > d[u] + edges[id].cost) {
                    d[v] = d[u] + edges[id].cost;
                    p[v] = id;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    long long flow() {
        long long flow = 0;
        long long cost = 0;
        vector<long long> d;
        vector<int> p;
        while (flow < k) {
            shortest_paths(s, d, p);
            if (d[t] == INF)
                break;
            // find max flow on that path
            long long f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, edges[p[cur]].cap);
                cur = edges[p[cur]].u;
            }
            // apply flow
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                edges[p[cur]].cap -= f;
                edges[p[cur]^1].cap += f;
                cur = edges[p[cur]].u;
            }
            //ans.push_back({flow, cost});
        }
        if (flow < k)
            return -1;
        else
            return cost;
    }
};

int tt = 1, n, m, k, q;
bool can[55][55];

// check long long
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            can[i][j] = true;
    for (int i = 0; i < q; i++) {
        int t, l, r, v;
        cin >> t >> l >> r >> v;
        if (t == 1) {
            for (int j = l; j <= r; j++)
                for (int u = 1; u < v; u++)
                    can[j][u] = false;
        } else {
            for (int j = l; j <= r; j++)
                for (int u = n; u > v; u--)
                    can[j][u] = false;
        }
    }
    int N = 2+2*n*n+2*n;
    MinCostFlow G(N, n, 0, N-1);
    for (int i = 1; i <= n; i++)
        G.add_edge(0, i, 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (can[i][j])
                G.add_edge(i, i*n+j, 1, 0);
            G.add_edge(i*n+j, n*n+n+j, 1, 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G.add_edge(n*n+n+i, n*n+2*n+(i-1)*n+j, 1, 2*j-1);
            G.add_edge(n*n+2*n+(i-1)*n+j, N-1, G.INF, 0);
        }
    }
    cout << G.flow() << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/max_xor.cpp
```cpp
/**
 *  Reference solution using calculation of maximum pairwise xor in array
 *  Codeforces 1625 D "Binary Spiders"
 *  https://codeforces.com/contest/1625/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<int> a;

// check long long
void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto& x : a)
        cin >> x;
    if (k == 0) {
        cout << n << "\n";
        for (int i = 0; i < n; i++)
            cout << i+1 << " ";
        cout << "\n";
        return;
    }
    int m = 32-__builtin_clz(k);
    unordered_map<int,vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] >> m].push_back(i);
    }
    vector<int> res;
    for (auto& p : mp) {
        int mx = 0, mask = 0;
        pii r;
        unordered_map<int, int> st;
        for (int b = m-1; b >= 0; b--) {
            if (mx >= k)
                break;
            mask |= (1 << b);
            for (int i = 0; i < (int)p.second.size(); i++) {
                st[a[p.second[i]] & mask] = p.second[i];
            }
            int new_mx = mx | (1 << b);
            for (pii pr : st) {
                if (st.find(new_mx ^ pr.first) != st.end()) {
                    mx = new_mx;
                    r = {st[new_mx ^ pr.first], pr.second};
                    break;
                }
            }
            st.clear();
        }
        if (mx >= k) {
            res.push_back(r.first);
            res.push_back(r.second);
        } else {
            res.push_back(p.second[0]);
        }
    }
    if (res.size() < 2) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << "\n";
    for (int v : res)
        cout << v+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/gauss_elim_mod.cpp
```cpp
/**
 *  Reference solution using Gaussian elimination for modular 
 *  Codeforces 1616 F "Tricolor Triangles"
 *  https://codeforces.com/contest/1616/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int((v_ + MOD) % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};
const int MOD = 3;
// const int MOD = 998244353;
using num = ModNum<MOD>;
int gauss(vector<vector<num>> a, vector<num> &ans) {
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (a[i][col].v > a[sel][col].v)
                sel = i;
        if (a[sel][col] == num(0))
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
        for (int i = 0; i < n; ++i)
            if (i != row) {
                num c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        num sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (sum != a[i][m])
            return 0;
    }
    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}

int tt = 1, n, m;
int adj[70][70];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = -1;
    vector<vector<num>> a;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u][v] = i;
        adj[v][u] = i;
        if (c != -1) {
            a.emplace_back(m+1, num(0));
            a.back()[i] = num(1);
            a.back()[m] = num(c-1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (adj[i][j] == -1)
                continue;
            for (int k = j+1; k < n; k++) {
                if (adj[i][k] == -1 || adj[j][k] == -1)
                    continue;
                // connected
                a.emplace_back(m+1, num(0));
                a.back()[adj[i][j]] = num(1);
                a.back()[adj[i][k]] = num(1);
                a.back()[adj[j][k]] = num(1);
            }
        }
    }
    if (a.empty()) {
        for (int i = 0; i < m; i++)
            cout << 1 << " \n"[i+1==m];
        return;
    }
    vector<num> ans;
    int res = gauss(a, ans);
    if (res == 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < m; i++) {
        cout << (int)ans[i]+1 << " \n"[i+1==m];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

```
\newpage

# reference/max_flow.cpp
```cpp
/**
 *  Reference solution using max flow
 *  Codeforces 1473 F "Strange Set"
 *  https://codeforces.com/contest/1473/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

// Dinic's algorithm for max flow
struct FlowEdge {
    int u, v;
    long long cap, flow = 0;
    FlowEdge(int u, int v, long long cap) : u(u), v(v), cap(cap) {}
};
struct MaxFlow {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    MaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, long long cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].v] != -1)
                    continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int u, long long pushed) {
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;
        for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
}; 

int tt = 1, n, m;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    MaxFlow G(n+2, n, n+1);
    vector<int> last(101, -1);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            res += b[i];
            G.add_edge(n, i, b[i]);
        } else {
            G.add_edge(i, n+1, -b[i]);
        }
        for (int j = 1; j <= 100; j++) {
            if (a[i] % j == 0 && last[j] != -1) {
                G.add_edge(i, last[j], 1e9);
            }
        }
        last[a[i]] = i;
    }
    cout << res - G.flow() << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/rmq.cpp
```cpp
/**
 *  Reference Solution using Range Minimun Query
 *  Codeforces 1473 D "Program"
 *  https://codeforces.com/contest/1473/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

template <typename T, class Compare = less<T>>
class RMQ : private Compare {
    vector<vector<T>> spt;
    Compare compare;
    int n, lim;
private:
    const T& _compare(const T& a, const T& b) const {
        return Compare::operator()(a, b) ? a : b;
    }
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = _compare(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a, const Compare& comp_ = Compare()) :
        n(a.size()), lim(floor(log2(n)+1)), compare(comp_) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = _compare(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};

int t, n, m;

void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr (n+1, 0);
    for (int i = 1; i <= n; ++i)
        arr[i] = arr[i-1] + (s[i-1] == '+' ? 1 : -1);
    RMQ<int> mn(arr);
    RMQ<int, greater<int>> mx(arr);
    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        int mn1 = mn.query(0,l-1);
        int mx1 = mx.query(0,l-1);
        if (r == n) {
            cout << (mx1-mn1+1) << "\n";
            continue;
        }
        int mn2 = mn.query(r+1,n)-arr[r]+arr[l-1];
        int mx2 = mx.query(r+1,n)-arr[r]+arr[l-1];
        cout << (max(mx2,mx1)-min(mn2,mn1)+1) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/sweepline.cpp
```cpp
/**
 *  Reference solution using sweepline technique
 *  Codeforces 1420 D "Rescue Nibel!"
 *  https://codeforces.com/contest/1420/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int((v_ + MOD) % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

// const int MOD = 1e9+7;
const int MOD = 998244353;
using num = ModNum<MOD>;
num fact[300005];
int tt = 1, n, m;

num choose(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] / fact[n-k] / fact[k];
}

void solve() {
    int k;
    cin >> n >> k;
    vector<pll> a(n);
    for (auto& x : a)
        cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    // sweep line
    num res = 0;
    int num_old = 0, num_new = 0;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first < a[i].first) {
            pq.pop();
            num_old--;
        }
        pq.push({a[i].second, i});
        num_new++;
        if (i+1 < n && a[i+1].first == a[i].first)
            continue;
        //cout << num_old << "/" << num_new << " ";
        res += (choose(num_old + num_new, k) - choose(num_old, k));
        num_old += num_new;
        num_new = 0;
        //cout << res << " ";
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    fact[0] = 1;
    for (int i = 1; i <= 300000; i++)
        fact[i] = fact[i-1] * i;
    while (tt--)
        solve();
    return 0;
}

```
\newpage

# reference/union_find.cpp
```cpp
/**
 *  Reference solution using Dijkstra's Algorithm and Union Find
 *  Codeforces 1253 F "Cheap Robot"
 *  https://codeforces.com/contest/1253/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

const int64_t INF = 1e18;
int t = 1, n, m, k, q;
vector<vector<pll>> adj;
vector<ll> dist, res;
vector<int> parent, sz, query;
vector<vector<int>> token;
 
int find_set(int v) {
    if (parent[v] == v)
        return v;
    return find_set(parent[v]);
}
bool union_sets(int v, int u, ll cap) {
    u = find_set(u), v = find_set(v);
    if (u == v) return false;
    if (sz[v] < sz[u]) swap(u, v);
    for (int tk : token[u]) { // Move token to the new parent
        int other = tk^1;
        int i = tk/2;
        if (find_set(query[other]) == v)
            res[i] = cap;
        token[v].push_back(tk);
    }
    token[u] = vector<int> (0);
 
    sz[v] += sz[u];
    parent[u] = v;
    return true;
}
 
void solve() {
    cin >> n >> m >> k >> q;
    // Initialize vectors
    adj.resize(n);
    token.resize(n);
    dist.assign(n, INF);
    parent.assign(n, 0);
    sz.assign(n, 0);
    query.assign(2*q, 0);
    res.assign(q, 0);
    // Read graph
    vector<array<ll,3>> edges;
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    }
    // Multi-soure Dijkstra's algorithm
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int v = 0; v < k; ++v) {
        pq.push({0, v});
        dist[v] = 0;
    }
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (d != dist[v])
            continue;
        for (auto e : adj[v]) {
            ll u = e.first, w = e.second;
            if (dist[v]+w < dist[u]) {
                dist[u] = dist[v]+w;
                pq.push({dist[u], u});
            }
        }
    }
    // Compute the new weight of the edges
    for (auto& e : edges)
        e[0] += dist[e[1]] + dist[e[2]];
    sort(edges.begin(), edges.end());
    // Read query
    for (int i = 0; i < q; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        --n1, --n2;
        query[2*i] = n1, query[2*i+1] = n2;
        token[n1].push_back(2*i);
        token[n2].push_back(2*i+1);
    }
    // Union Find
    for (int v = 0; v < n; ++v) {
        parent[v] = v;
        sz[v] = 1;
    }
    for (auto e : edges)
        union_sets(e[2], e[1], e[0]);
    for (int i = 0; i < q; ++i)
        cout << res[i] << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/convex_hull.cpp
```cpp
/**
 *  Reference solution using convex hull trick
 *  15-451 Fall 2021 Homework 7 Programming "Farthest Pair"
 *  https://www.cs.cmu.edu/~15451-f21/hws/hw7.pdf
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>
#define pt  array<double,2>

// Convex hull using Graham scan
// Should not contain dulicate points
bool cw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) <= 0;
}
bool ccw(pt a, pt b, pt c) {
    return a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]) > 0;
}
vector<pt> convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return {};
    sort(a.begin(), a.end());
    pt p1 = a[0], p2 = a.back();
    vector<pt> u, d;
    u.push_back(p1);
    d.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (u.size() >= 2 && !cw(u[u.size()-2], u[u.size()-1], a[i]))
                u.pop_back();
            u.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (d.size() >= 2 && !ccw(d[d.size()-2], d[d.size()-1], a[i]))
                d.pop_back();
            d.push_back(a[i]);
        }
    }
    vector<pt> res;
    for (int i = 0; i < (int)u.size(); i++)
        res.push_back(u[i]);
    for (int i = d.size() - 2; i > 0; i--)
        res.push_back(d[i]);
    return res;
}

int tt = 1, n, m;

double d2(pt x, pt y) {
    return (x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1]);
}

void solve() {
    cin >> n;
    vector<pt> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1];
    vector<pt> b = convex_hull(a);
    m = b.size();
    int j = 0;
    double res = 0.0;
    for (int i = 0; i < m; i++) {
        while (d2(b[i],b[j]) < d2(b[i],b[(j+1)%n])) {
            j++;
            j %= n;
        }
        res = max(res, d2(b[i], b[j]));
    }
    cout << fixed << setprecision(10) << sqrt(res) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# reference/segtree.cpp
```cpp
/**
 *  Reference solution using Segment Tree
 *  Codeforces 1478 E "Nezzar and Binary String"
 *  https://codeforces.com/contest/1478/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T>
class SegTree {
    int n;
    vector<T> tree;
    vector<bool> mark;
private:
    void _build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            mark[v] = true;
        } else {
            int tmid = tl + (tr - tl) / 2;
            _build(a, v*2, tl, tmid);
            _build(a, v*2+1, tmid+1, tr);
            tree[v] = 0;
        }
    }
    void _update(int v, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            tree[v] = val;
            mark[v] = true;
            return;
        }
        if (mark[v]) {
            tree[v*2] = tree[v*2+1] = tree[v];
            mark[v*2] = mark[v*2+1] = true;
            mark[v] = false;
        }
        int tmid = tl + (tr - tl) / 2;
        _update(v*2, tl, tmid, l, min(r, tmid), val);
        _update(v*2+1, tmid+1, tr, max(l, tmid+1), r, val);
    }
    T _sum(int v, int tl, int tr, int l, int r) {
        if (l > r || tr < l || tl > r)
            return 0;
        if (mark[v] && tr >= r && tl <= l)
            return tree[v] * (r-l+1);
        int tmid = tl + (tr - tl) / 2;
        return _sum(v*2, tl, tmid, l, min(r, tmid)) +
               _sum(v*2+1, tmid+1, tr, max(l, tmid+1), r);
    }
    T _get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return tree[v];
        if (mark[v])
            return tree[v];
        int tmid = tl + (tr - tl) / 2;
        if (pos <= tmid)
            return _get(v*2, tl, tmid, pos);
        else
            return _get(v*2+1, tmid+1, tr, pos);
    }
public:
    SegTree(const vector<T>& a) {
        tree.assign(4*n, 0);
        mark.assign(4*n, false);
        _build(a, 1, 0, n-1);
    }
    friend ostream& operator<<(ostream& os, SegTree st) {
        for (int i = 0; i < st.n; ++i)
            os << st.get(i) << (i == st.n-1 ? "\n" : " ");
        return os;
    }
    void update(int val, int l, int r) { _update(1, 0, n-1, l,   r,   val); }
    void update(int val, int pos)      { _update(1, 0, n-1, pos, pos, val); }
    T sum(int l, int r)                { return _sum(1, 0, n-1, l, r); }
    T get(int pos)                     { return _get(1, 0, n-1, pos);  }
    T operator[](int pos)              { return get(pos); }
};

int t = 1, n, m, k, q;

void solve() {
    cin >> n >> q;
    string s, f;
    cin >> s;
    cin >> f;
    vector<int> a (n, 0);
    for (int i = 0; i < n; ++i) {
        if (f[i] == '1')
            a[i] = 1;
    }
    SegTree<int> st (a);
    vector<int> lx (q, 0);
    vector<int> rx (q, 0);
    for (int i = 0; i < q; ++i) {
        cin >> lx[i] >> rx[i];
        --lx[i], --rx[i];
    }
    for (int i = q-1; i >= 0; --i) {
        int l = lx[i], r = rx[i];
        int cnt = st.sum(l, r);
        if (cnt * 2 > r-l+1)
            st.update(1, l, r);
        else if (cnt * 2 < r-l+1)
            st.update(0, l, r);
        else {
            cout << "NO\n";
            return;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (st.get(i) != (int)(s[i]-'0')) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


```
\newpage

# algebra/sos_inv.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

template <class T_in, class T_out>
vector<T_out> inverse_sum_over_subsets(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i];
    for (int i = 0; i < n; i++)
        for (int base = 0; base < (1 << n); base += (1 << (i+1)))
            for (int mask = base; mask < base + (1 << i); mask++)
                f[mask + (1 << i)] -= f[mask];
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) % 2 == 0)
            f[mask] = 0-f[mask];
    }
    return f;
}

// check long long
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

```
\newpage

# algebra/sos.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

template <class T_in, class T_out>
vector<T_out> sum_over_subsets(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i];
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i))
                f[mask] += f[mask^(1<<i)];
        }
    }
    return f;

}

// check long long
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

```
\newpage

# algebra/prime_factorize.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

vector<pll> factorize(ll n) {
    vector<pll> res;
    ll cnt = 0;
    while (n % 2 == 0)
        cnt++, n /= 2;
    if (cnt > 0)
        res.push_back({2, cnt});
    for (int i = 3; i <= sqrt(n); i += 2) {
        cnt = 0;
        while (n % i == 0)
            cnt++, n /= i;
        if (cnt > 0)
            res.push_back({i, cnt});
    }
    if (n != 1)
        res.push_back({n, 1});
    return res;
}

void solve() {
    ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# algebra/fft.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) 
        N <<= 1;
    fa.resize(N);
    fb.resize(N);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(N);
    for (int i = 0; i < N; i++)
        result[i] = round(fa[i].real());
    return result;
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

```
\newpage

# algebra/sieve.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
const int MAXN = 2e5+10;

int tt = 1, n, m, k;
bool is_composite[MAXN];
vector<int> prime;

void sieve(int n) {
	fill(is_composite, is_composite+n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i])
            prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0)
                break;
		}
	}
}


// check long long
void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    sieve(MAXN);
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# algebra/mobius.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
const int MAXN = 2e5+10;

int tt = 1, n, m, k;
int mob[MAXN];

void mobius() {
    mob[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        mob[i]--;
        for (int j = i + i; j < MAXN; j += i) {
            mob[j] -= mob[i];
        }
    }
}

// check long long
void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    mobius();
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# algebra/max_xor.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    // finds maximum xor of any two numbers in a
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int maxx = 0, mask = 0;
    unordered_set<int> se;
    for (int i = 30; i >= 0; i--) {
        mask |= (1 << i);
        for (int i = 0; i < (int)a.size(); ++i)
            se.insert(a[i] & mask);
        int new_maxx = maxx | (1 << i);
        for (int prefix : se) {
            if (se.count(new_maxx ^ prefix)) {
                maxx = new_maxx;
                break;
            }
        }
        se.clear();
    }
    // result is maxx
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

```
\newpage

# algebra/modnum.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int((v_ + MOD) % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

const int MOD = 1e9+7;
// const int MOD = 998244353;
using num = ModNum<MOD>;
int tt = 1, n, m;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

```
\newpage

# algebra/frac.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

struct Fraction {
    int64_t m, n;
private:
    static int64_t gcd(int64_t a, int64_t b) {
        if (a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    static void upd(int64_t& a, int64_t& b) {
        int64_t g = a ? gcd(abs(a), b) : b;
        a /= g, b /= g;
    }
public:
    Fraction() : m(0), n(1) {}
    Fraction(int64_t a) : m(a), n(1) {}
    Fraction(int64_t a, int64_t b) {
        assert(b > 0);
        m = a, n = b;
        upd(m, n);
    }
    explicit operator int () const { return int(m / n); }
    explicit operator int64_t () const { return m / n; }
    explicit operator double () const { return double(m) / double(n); }
    friend ostream& operator<<(ostream& os, const Fraction& x) {
        if (x.m == 0) return os << 0;
        if (x.n == 1) return os << x.m;
        return os << x.m << "/" << x.n;
    }
    friend istream& operator>>(istream& is, Fraction& x) {
        return is >> x.m >> x.n;
    }
    friend bool operator==(const Fraction& a, const Fraction& b) {
        return a.m == b.m && a.n == b.n;
    }
    friend bool operator!=(const Fraction& a, const Fraction& b) {
        return !(a == b);
    }
    Fraction neg() const { return Fraction(-m, n); }
    Fraction inv() const { 
        assert(m != 0);
        return m < 0 ? Fraction(-n, -m) : Fraction(n, m);
    }
    Fraction& operator++() { m += n; return *this; }
    Fraction& operator--() { m -= n; return *this; }
    Fraction& operator+=(const Fraction& o) {
        int64_t g = gcd(n, o.n);
        m = m * (o.n / g) + o.m * (n / g);
        n *= (o.n / g);
        upd(m, n);
        return *this;
    }
    Fraction& operator-=(const Fraction& o) { return *this += o.neg(); }
    Fraction& operator*=(const Fraction& o) {
        m *= o.m, n *= o.n;
        upd(m, n);
        return *this;
    }
    Fraction& operator/=(const Fraction& o) {
        return *this *= o.inv();
    }
    friend Fraction operator+(const Fraction& a, const Fraction& b) {
        return Fraction(a) += b;
    }
    friend Fraction operator-(const Fraction& a, const Fraction& b) {
        return Fraction(a) -= b;
    }
    friend Fraction operator*(const Fraction& a, const Fraction& b) {
        return Fraction(a) *= b;
    }
    friend Fraction operator/(const Fraction& a, const Fraction& b) {
        return Fraction(a) /= b;
    }
    friend Fraction pow(const Fraction& a, int e) {
        if (e < 0) return pow(a, -e).inv();
        Fraction res = 1, b = a;
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

int t = 1, n, m, k, q;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# algebra/gauss_elim_mod.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int((v_ + MOD) % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};
const int MOD = 1e9+7;
// const int MOD = 998244353;
using num = ModNum<MOD>;
int gauss(vector<vector<num>> a, vector<num> &ans) {
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (a[i][col].v > a[sel][col].v)
                sel = i;
        if (a[sel][col] == num(0))
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
        for (int i = 0; i < n; ++i)
            if (i != row) {
                num c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        num sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (sum != a[i][m])
            return 0;
    }
    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}

int tt = 1, n, m;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

```
\newpage

# algebra/matrix.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T> 
struct Matrix {
    int m, n;
    vector<vector<T>> data;
    Matrix(int x, int y) : m(x), n(y) {
        data.assign(m, vector<T>(n, (T)0));
    }
    Matrix(int x, int y, T val) : m(x), n(y) {
        data.assign(m, vector<T>(n, val));
    }
    Matrix(const vector<vector<T>>& a) : m(a.size()), n(a[0].size()) {
        data = a;
    }
public:
    vector<T>& operator [] (int i) { return data[i]; }
    T& operator [] (pair<int, int> id) { return data[id.first][id.second]; }
    Matrix tp() {
        // Transpose the Matrix
        Matrix<T> res(n, m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                res[j][i] = data[i][j];
        return res;
    }
    Matrix& assign(int x, int y, T val) {
        m = x, n = y;
        data = vector<vector<T>> (x, vector<T> (y, val));
        return *this;
    }
    Matrix& resize(int x, int y) {
        assert(m * n == x * y);
        vector<vector<T>> data_n(x, vector<T>(y));
        for (int i = 0; i < m * n; i++) {
            data_n[i / y][i % y] = data[i / n][i % n];
        }
        data = data_n;
        return *this;
    }
    static Matrix I(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = 1;
        return res;
    }
    static Matrix I(int n, T one) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) res[{i, i}] = one;
        return res;
    }
    friend ostream& operator<<(ostream& os, const Matrix& a) {
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < a.n; ++j)
                os << a.data[i][j] << (j+1 == a.n ? "\n" : " ");
        return os;
    }
    friend istream& operator>>(istream& is, const Matrix& a) {
        int m, n;
        is >> m >> n;
        a = Matrix(m, n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                is >> a[i][j];
        return is;
    }
    Matrix& operator+=(const Matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += o.data[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& o) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= o.data[i][j];
        return *this;
    }
    Matrix& operator+=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] += c;
        return *this;
    }
    Matrix& operator-=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] -= c;
        return *this;
    }
    Matrix& operator*=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] *= c;
        return *this;
    }
    Matrix& operator/=(T c) {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                data[i][j] /= c;
        return *this;
    }
    friend Matrix operator+(const Matrix& a, const Matrix& b) {
        return Matrix(a) += b;
    }
    friend Matrix operator-(const Matrix& a, const Matrix& b) {
        return Matrix(a) -= b;
    }
    friend Matrix operator+(const Matrix& a, T c) {
        return Matrix(a) += c;
    }
    friend Matrix operator-(const Matrix& a, T c) {
        return Matrix(a) -= c;
    }
    friend Matrix operator*(const Matrix& a, T c) {
        return Matrix(a) *= c;
    }
    friend Matrix operator/(const Matrix& a, T c) {
        return Matrix(a) /= c;
    }
    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        assert(a.n == b.m);
        Matrix prod (a.m, b.n);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < b.m; ++j)
                for (int k = 0; k < b.n; ++k)
                    prod[i][k] += a.data[i][j] * b.data[j][k];
        return prod;
    }
    friend Matrix operator==(const Matrix& a, const Matrix& b) {
        assert(a.n == b.n);
        assert(a.m == b.m);
        for (int i = 0; i < a.m; ++i)
            for (int j = 0; j < a.n; ++j)
                if (a[i][j] != b[i][j])
                    return false;
        return true;
    }
    friend Matrix operator!=(const Matrix& a, const Matrix& b) {
        return !(a == b);
    }
    friend Matrix pow(const Matrix& a, int e) {
        assert(a.m == a.n);
        Matrix res = I(a.m), b = a;
        while (e) {
            if (e % 2) res = res * b;
            e /= 2;
            b = b * b;
        }
        return res;
    }
};
template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int(v_ % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

const int MOD = 1e9+7;
using num = ModNum<MOD>;
using mat = Matrix<num>;
int t = 1, n, m, k, q;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# algebra/prime_test.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

void solve() {
    // check long long
    ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```
\newpage

# algebra/ntt.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int MOD = 7340033;
const int ROOT = 5;
const int ROOT_1 = 4404020;
const int ROOT_PW = 1 << 20;

void ntt(vector<ll>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? ROOT_1 : ROOT;
        for (int i = len; i < ROOT_PW; i <<= 1)
            wlen = (1LL * wlen * wlen % MOD);

        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (1LL * a[i+j+len/2] * w % MOD);
                a[i+j] = u + v < MOD ? u + v : u + v - MOD;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;
                w = (1LL * w * wlen % MOD);
            }
        }
    }

    if (invert) {
        ll n_1 = inverse(n, MOD);
        for (ll& x : a)
            x = (1LL * x * n_1 % MOD);
    }
}
vector<int> multiply(vector<int>& a, vector<int>& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int N = 1;
    while (N < a.size() + b.size()) 
        N <<= 1;
    fa.resize(N);
    fb.resize(N);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < N; i++)
        fa[i] = (fa[i] * fb[i]) % MOD;
    ntt(fa, true);

    vector<int> result(N);
    for (int i = 0; i < N; i++)
        result[i] = (int)fa[i];
    return result;
}

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

```
\newpage

# algebra/phi.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int MAXN = 2e5+10;
ll phi[MAXN];

void compute_phi(ll n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

// check long long
void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    compute_phi(2e5+5);
    while (tt--) {
        solve();
    }
    return 0;
}

```
\newpage

# algebra/gauss_elim_dbl.cpp
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

const double EPS = 1e-9;

template <class T>
int gauss(vector<vector<double>> a, vector<double>& ans) {
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }
    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}

int tt = 1, n, m, k;

// check long long
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

```
