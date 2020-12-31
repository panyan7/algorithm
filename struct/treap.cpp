#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct TreapNode {
    T data;
    int priority;
    TreapNode *l, *r;
    TreapNode(T d, int p) {
        data = d;
        priority = p;
        l = nullptr;
        r = nullptr;
    }
};

template<typename T>
struct Treap {
    TreapNode<T> *root;
    Treap() {
        root = nullptr;
    }
    void rot_left() {
        assert(root != nullptr);
        TreapNode<T> *R = root->r;
        TreapNode<T> *X = root->r->l;
        R->l = root;
        root->r = X;
        root = R;
    }
    void rot_right() {
        assert(root != nullptr);
        TreapNode<T> *L = root->l;
        TreapNode<T> *Y = root->l->r;
        L->r = root;
        root->l = Y;
        root = L;
    }
};
