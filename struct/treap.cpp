#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

template <typename T>
struct node {
    T key;
    int prior;
    node<T> *l, *r;
    node () {}
    node (T k, int p) { key = k; prior = p; l = nullptr; r = nullptr; }
private:
    typedef node * node_t;
public:
    friend bool operator > (const node& a, const node& b) { 
        return a.key > b.key;
    }
    friend bool operator < (const node& a, const node& b) {
        return a.key < b.key;
    }
    friend bool operator == (const node& a, const node& b) {
        return a.key == b.key;
    }
    friend ostream& operator << (ostream& o, const node& a) {
        o << a.key; return o;
    }
    static void split(node_t t, T key, node_t low, node_t hi) {
        if (t == nullptr) low = hi = nullptr;
        else if (key < t->key)
            split(t->l, key, low, t->l), hi = t;
        else
            split(t->r, key, t->r, hi), low = t;
    }
    static void insert(node_t& t, node_t it) {
        if (t == nullptr)
            t = it;
        else if (it->prior > t->prior)
            split(t, it->key, it->l, it->r), t = it;
        else
            insert(it->key < t->key ? t->l : t->r, it);
    }
    static void merge(node_t& t, node_t l, node_t r) {
        if (!l || !r)
            t = l ? l : r;
        else if (l->prior > r->prior)
            merge(l->r, l->r, r), t = l;
        else
            merge(r->l, l, r->l), t = r;
    }
    static void erase(node_t& t, T key) {
        if (t->key == key) {
            node_t th = t;
            merge(t, t->l, t->r);
            delete th;
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }
    static node_t unite(node_t l, node_t r) {
        if (!l || !r) return l ? l : r;
        if (l->prior < r->prior) swap(l, r);
        node_t lt, rt;
        split(r, l->key, lt, rt);
        l->l = unite(l->l, lt);
        l->r = unite(l->r, rt);
        return l;
    }
};

template <typename T>
struct treap {
    node<T> *root;
    treap () { root = nullptr; }
    treap (T d, int p) { root = new node<T> (d, p); }
    treap (node<T> *n) { root = n; }
public:
    explicit operator node<T>() { return *root; }
    // Overload operator
    friend bool operator < (const treap& a, const treap& b) {
        return *a.root < *b.root;
    }
    friend bool operator > (const treap& a, const treap& b) {
        return *a.root > *b.root;
    }
    friend bool operator == (const treap& a, const treap& b) {
        return *a.root == *b.root;
    }
    friend ostream& operator << (ostream& o, const treap& a) {
        o << *a.root; return o;
    }
    // Access variables
    T key() { assert(root != nullptr); return root->key; }
    int priority () { assert(root != nullptr); return root->prior; }
    treap l() const { assert(root != nullptr); return treap(root->l); }
    treap r() const { assert(root != nullptr); return treap(root->r); }
    // Functions
    treap split(int key, treap& low, treap& hi) {
        node<T>::split(root, key, low.root, hi.root);
        return *this;
    }
    treap insert(treap& it) {
        node<T>::insert(root, it.root);
        return *this;
    }
    treap merge(treap& l, treap& r) {
        node<T>::merge(root, l.root, r.root);
        return *this;
    }
    treap erase(T key) {
        node<T>::erase(root, key);
        return *this;
    }
    static treap unite(treap& l, treap& r) {
        node<T> *res = node<T>::unite(l.root, r.root);
        return treap(res);
    }
};

int t;

int main() {
    treap<int> t1 (1,1), t2 (2,0), t3 (3,2);
    cout << t1.key() << " " << t2.key() << endl;
    t1.insert(t2);
    t1.erase(1);
    t1.merge(t2, t3);
    treap<int> t4 = treap<int>::unite(t2, t3);
    cout << t1.key() << endl;
    cout << t1.l().key() << endl;
    cout << t4 << t4.l() << endl;
    return 0;
}
