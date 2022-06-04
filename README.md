# Algorithms
I collected several useful algorithms and tips in this repo for me to use in contests. All of them are implemented in C++.
Many of them are adapted from [CP Algorithms](https://cp-algorithms.com/index.html) and various [Codeforces](https://codeforces.com/) posts. 

This repository is mainly for personal use. I do not guarantee that all the codes are correct.

## Full List of Algorithms

### Algebra
In directory `algebra/`
- Fast Fourier transform `fft.cpp`
- Fraction as pair of integers `frac.cpp`
- Gaussian elimination `gaussian_elim.cpp`
- Gaussian elimination with modular number `gaussian_elim_mod.cpp`
- Matrix with efficient multiplication and exponentiation `matrix.cpp`
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
- Combinatorics template `combinatorics.cpp`
- Stirling number `stirling.cpp` (TODO)

### Geometry
In directory `geometry/`
- Basic geometry operations `basic.cpp`
- Convex Hull `convex_hull.cpp`

### Graph Theory
In directory `graph/`
- Bellman-Ford algorithm with negative cycle detection `bellman_ford.cpp`
- Breadth-first search `bfs.cpp`
- Binary lifting on forests `binary_lifting.cpp`
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
- Aho-Corasick algorithm for string searching `aho_corasick.cpp` (TODO)
- Knuth-Morris-Pratt (KMP) algorithm for string searching `kmp.cpp`

### Data Structures
In directory `struct/`
- Fenwick tree `fenwick.cpp`
- Minimum stack `min_stack.cpp`
- Minimum queue `min_queue.cpp`
- Ordered set with indexing `ordered_set.cpp`
- Randomized hash function for unordered_map `random_hash.cpp`
- Range minimum/maximum query with sparse table `rmq.cpp`
- Segment tree with generic query function and assignment query `segtree.cpp`
- 2D Segment tree with generic query function and assignment query `segtree_2d.cpp`
- Segment tree with range add query and max query `segtree_range_add.cpp`
- Segment tree with range assignment query and sum query `segtree_range_assign.cpp`
- Splay tree `splay.cpp` (unfinished)
- SQRT decomposition `sqrt_decomposition.cpp`
- Treap `treap.cpp`
- Trie `trie.cpp`

### Generic Algorithm Design Techniques
In directory `technique/`
- Sweep Line `sweepline.cpp`
- Two pointers `two_pointers.cpp`

### Miscellaneous Important Problems
In directory `misc/`
- Number of inversions with segment tree `inversions.cpp`
- Longest increasing subsequence `longest_increasing_subseq.cpp`
- Maximum subarray sum `max_subarray_sum.cpp`
- Maximum subarray sum with queries `max_subarray_sum_query.cpp`
- Finding maximum pairwise xor value in array `max_xor.cpp`

## Some Tips for Competitive Programming
### Algorithm Design Ideas
- Always think of two-pointers first when dealing with range and need a O(n) solution.
- Similarly, always think of sweepline when you can transform inputs into ranges explicitly and need to consider the intersection of them.
- You can also use sweepline to merge ranges.
- Binary search can be used on any monotonic sequences. This includes segment tree with range max/min query.
- Think of brute force, or if you can reduce the problem to a brute force problem with better input sizes (like O(log n)).
- Monotonic stack is also useful when you want to merge some elements, or erase elements such that their effect are covered by others.
- Think about min-cut when you have precedence in max-flow problems. Only keep the objects having negative cost that is required by others and positive cost that requires some others.
- Binary lifting can be used to solve non-LCA problems too! Whenever you're doing something like `x = nxt[x]`, and there is a topological ordering of the elements, it is a good idea to use binary lifting to improve the running time to O(log n).
- When you need to construct x operations to do something, first think of whether you can solve it with constant number of operations.
- When you need to keep track of the number of unique elements, you can store a table for the frequency of the elements, and increase the count when some frequency change from 0 to 1 and decrease when some frequency change from 1 to 0.

### Utilizing Input Range
- It is important to read the input ranges correctly!
- When the problem only gives a few inputs, and the range of the input is something like 1e6, it is probably linear. If O(1) or O(log n) solutions exist, they would give 1e9 range.
- When the numbers are 1e6 or smaller, the solution is probably pseudo-polynomial time and depends on the size of these numbers. Because otherwise they would give numbers of 1e9.
- Typically when the list is 1e5 and the numbers are 1e9, you cannot do square root time operations like prime factorization. But if they are 1e6, you probably want to consider that.

### Writing Clean Code
- When you're making queries to sum of absolute values minus some number, you can precompute the points that the solution change, and calculate p, the number of positive - number of non-positive, and w, the sum of elements with signs +1 or -1. Then, you can calculate the query x by w - x * p. This is clean and easy to debug.
- Tree operations are slow in constant. So avoid using ordered set and map in general if you don't really need them. Vector + sort + removing duplicate with `a.erase(std::unique(a.begin(), a.end()), a.end())` is much faster than set in practice. Priority queue is also much faster than multiset, although their query complexities are both O(log n).
- If you want to calculate both the prefix and suffix quickly, you just need one prefix sum array, because it actually allows you to calculate the sum of every interval. When you have fewer arrays, you don't have to modify a lot during debugging. Also, if you only need prefix sum, you can do stuff like `a[i] += a[i-1]`.
- If you don't need to modify the array, then use prefix sum or sparse table RMQ for range queries, instead of segment trees. The complexity is constant!
- Use `lower_bound` or `upper_bound` when you need to do binary search on an array, instead of implementing one yourself.
- When you binary search for a fixed precision, you can run for a fixed iteration, which is something at least log(precision). Typically something like 100 works.
- If you want to enumerate all subsets, use bitmask instead of precomputing stuff.
- If you need to use the powers of some constant, precompute them. Don't trust C++'s `pow` function.
- Do not use `unordered_map` and `unordered_set`! They could be hacked. If you really need to fit into tighter time bound, use randomized hash function.

### Debugging
- Did you use long long? Especially, when you do bitwise shift, use 1LL.
- When you use long long, did you use `LLONG_MAX` instead of `INT_MAX`?
- Did you confuse max and min?
- Did you confuse m and n?
- Are the containers initialized correctly? If there are multiple test cases, did you clear the containers?
- Are there array out of bound issues?
- Are the base case (and index) of dp correct?
- Did you do off by one for the index? Are the choices consistent throughout the program?
- Did you try test cases that cover all parts of your solution?
- Does the test case allow negative numbers and did you forget it?
- Are there precision errors? Specifically, when you use Python, int and float has different precisions, and float cannot represent large integers well.
- Did you confuse = and ==?
- For max flow, is the capacity constraint on edges or vertices?
- Did you change n and k to long long when it is necessary? Especially when you use something like `k * (k - 1) / 2`.
- Did you use 1 to n or 0 to n-1? In the previous case, did you use `i <= n` instead of `i < n`?
