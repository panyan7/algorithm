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
