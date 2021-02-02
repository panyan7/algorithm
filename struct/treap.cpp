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
