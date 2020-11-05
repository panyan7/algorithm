#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct TreapNode {
    T data;
    int priority;
    TreapNode *l, *r;
    TreapNode(T d, int p) {
        this->data = d;
        this->priority = p;
        this->l = nullptr;
        this->r = nullptr;
    }
};

template<typename T>
struct Treap {
    TreapNode<T> *root;
    Treap() {
        this->root = nullptr;
    }
    void rot_left() {
        assert(root != nullptr);
        TreapNode<T> *R = this->root->r;
        TreapNode<T> *X = this->root->r->l;
        R->l = this->root;
        this->root->r = X;
        this->root = R;
    }
    void rot_right() {
        assert(root != nullptr);
        TreapNode<T> *L = this->root->l;
        TreapNode<T> *Y = this->root->l->r;
        L->r = this->root;
        this->root->l = Y;
        this->root = L;
    }
};
