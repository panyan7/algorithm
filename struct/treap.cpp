#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct node {
    T key;
    int prior;
    node<T> *l, *r;
    node () {}
    node (T k, int p) {
        key = k;
        prior = p;
        l = nullptr;
        r = nullptr;
    }
private:
    typedef node * node_t;

public:
    friend bool operator > (const node& a, const node& b) { 
        return a.key > b.key;
    }
    friend bool operator < (const node& a, const node& b) {
        return a.key < b.key;
    }

    friend void split(node_t t, T key, node_t low, node_t hi) {
        if (t == nullptr) low = hi = nullptr;
        else if (key < t->key)
            split(t->l, key, low, t->l), hi = t;
        else
            split(t->r, key, t->r, hi), low = t;
    }
    friend void insert(node_t& t, node_t it) {
        if (t == nullptr)
            t = it;
        else if (it->prior > t->prior)
            split(t, it->key, it->l, it->r), t = it;
        else
            insert(it->key < t->key ? t->l : t->r, it);
    }
    friend void merge(node_t& t, node_t l, node_t r) {
        if (!l || !r)
            t = l ? l : r;
        else if (l->prior > r->prior)
            merge(l->r, l->r, r), t = l;
        else
            merge(r->l, l, r->l), t = r;
    }
    friend void erase(node_t& t, T key) {
        if (t->key == key) {
            node_t th = t;
            merge(t, t->l, t->r);
            delete th;
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }
    friend node_t unite(node_t l, node_t r) {
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
    treap (T d, int p) { *root = node<T> (d, p); }
    treap (node<T>* n) { root = n; }
public:
    T key() { assert(root != nullptr); return root->key; }
    int priority () { assert(root != nullptr); return root->prior; }
    treap l() const { assert(root != nullptr); return treap(root->l); }
    treap r() const { assert(root != nullptr); return treap(root->r); }
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
    treap erase(int key) {
        node<T>::erase(root, key);
        return *this;
    }
    friend treap unite(treap& l, treap& r) {
        node<T> *res = unite(l.root, r.root);
        return treap(res);
    }
};

int main() {
    node<int>* n1 = new node<int> (1, 1);
    node<int>* n2 = new node<int> (2, 0);
    treap<int> t1 (n1), t2 (n2);
    cout << t1.key() << " " << t2.key() << endl;
    t1.insert(t2);
    // insert(n1, n2);
    // cout << n1->key << " " << n1->r->key << endl;
    // cout << t2.l().key() << " " << t2.l().priority() << endl;
    // cout << t2.r().key() << " " << t2.r().priority() << endl;
    return 0;
}
