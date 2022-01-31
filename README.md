# Algorithms
I'm a noob who only started doing competitive programming during sophomore year in college. I collected several useful algorithms and tips in this repo for me to use in contests. All of them are implemented in C++. 
Many of them are adapted from [CP Algorithms](https://cp-algorithms.com/index.html) and various [Codeforces](https://codeforces.com/) posts. 

This repository is mainly for personal use. The codes might not be useful to others, but I'll make it public in case anyone needs it. I added my own template and predefined a command to copy the file in my shell, so I can straightly work on these templates during a contest.

My homepage: [Yan Pan](https://panyan7.github.io/)

My Codeforces handles: [YanPan](https://codeforces.com/profile/YanPan) and [panyan7](https://codeforces.com/profile/panyan7).

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
- Testing primality `prime_test.cpp`
- Prime factorization `prime_factorize.cpp`
- Sieve of Eratosthenes `sieve.cpp`
- Sum over subsets `sos.cpp`
- Inverse sum over subsets `sos_inv.cpp`

### Combinatorics
In directory `combinatorics/`


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
- Depth-first search `dfs.cpp`
- Dijkstra's algorithm `dijkstra.cpp`
- Floyd-Warshall algorithm for all sources shortest path `floyd_warshall.cpp`
- Kahn's algorithm for topological sorting `kahn.cpp`
- Kruskal's algorithm for MST construction `kruskal.cpp`
- Lowest common ancestor with binary lifting `lca.cpp`
- Prim's algorithm for MST construction `prim.cpp`
- Strongly connected components `scc.cpp`
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

## Some Tips for Competitive Programming
### Algorithm Design Ideas
- Always think of two-pointers first when dealing with range and need a O(n) solution.
- Similarly, always think of sweepline when you can transform inputs into ranges explicitly and need to consider the intersection of them.
- You can also use sweepline to merge ranges.
- Binary search can be used on any monotonic sequences. This includes segment tree with range max/min query.
- Think of brute force, or if you can reduce the problem to a brute force problem with better input sizes.
### Using Input Range
- When the problem only gives a few inputs, and the range of the input is something like 1e6, it is probably linear.If O(1) or O(log n) solutions exist, they would give 1e9 range.
- When the numbers are 1e6 or smaller, the solution is probably pseudo-polynomial time and depends on the size of these numbers. Because otherwise they would give numbers of 1e9.
- Typically when the list is 1e5 and the numbers are 1e9, you cannot do square root time operations like prime factorization. But if they are 1e6, you probably want to consider that.
### Writing Clean Code
- When you're making queries to sum of absolute values minus some number, you can precompute the points that the solution change, and calculate p, the number of positive - number of non-positive, and w, the sum of elements with signs +1 or -1. Then, you can calculate the query x by w - x * p. This is clean and easy to debug.
