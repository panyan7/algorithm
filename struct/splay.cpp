#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

template <typename T>
struct SplayTree {
    struct Node {
        Node() {}
        Node(T val_): val(val_) {}
        T val = 0;
        array<Node*, 2> child;
        Node* parent;
        bool side() const {
            return parent->child[1] == this;
        }
        void rotate() {
            const auto p = parent;
            const bool i = side();

            if (p->parent) {
                p->parent->attach(p->side(), this);
            } else {
                parent = nullptr;
            }
            p->attach(i, child[!i]);
            attach(!i, p);
        }
        void splay() {
            for (; parent; rotate()) {
                if (parent->parent) {
                    (side() == parent->side() ? parent: this)->rotate();
                }
            }
        }
        array<Node*, 2> split() {
            splay();
            const auto right = child[1];
            if (right) {
                right->parent = nullptr;
            }
            this->right = nullptr;
            return {this, right};
        }
        void attach(bool side, Node *const new_node) {
            if (new_node) {
                new_node->parent = this;
            }
            child[side] = new_node;
        }
    };
    struct iterator {
        using iterator_category = bidirectional_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = ll;
    public:
        void operator--() { advance<false>(); }
        void operator++() { advance<true>(); }
        const T &operator*() { return node->value; }
        Node *node;
        iterator(Node *node_arg) : node(node_arg) {}
        bool operator==(const iterator oth) const {
            return node == oth.node;
        }
        bool operator!=(const iterator oth) const {
            return !(*this == oth);
        }
    private:
        template <bool dir> void advance() {
            if (node->child[1]) {
                node = extremum<!dir>(node->child[1]);
                return;
            }
            while (node->parent && node->side() == dir)
                node = node->parent;
            node = node->parent;
        }
    };
    Node* root = nullptr;
    ll n = 0;
    SplayTree() {}
    ~SplayTree() { destroy(root); }
    static void destroy(Node* const node) {
        if (!node) {
            return;
        }
        for (Node* const child : node->child) {
            destroy(child);
        }
        delete node;
    }
    void insert(Node* const x) {
        ++n;
        if (!root) {
            root = x;
            return;
        }
        auto y = root;
        while (true) {
            auto& nw = y->child[x->value > y->value];
            if (!nw) {
                nw = x;
                nw->parent = y;
                root = nw;
                nw->splay();
                return;
            }
            y = nw;
        }
        return;
    }
    void insert(const T& key) {
        insert(new Node{key});
    }
    void erase(Node* const x) {
        assert(x);
        x->splay();
        root = join(x->child[0], x->child[1]);
        delete x;
        --n;
    }
    void erase(const T& key) { erase(find(key)); }
    template <bool i> static Node* extremum(Node* x) {
        /* Return the extremum of the subtree x. Minimum if i is false,
         * maximum if i is true.*/
        assert(x);
        for(; x->child[i]; x = x->child[i]);
        return x;
    }
    static Node* join(Node* const a, Node* const b) {
        if (!a) {
            b->parent = nullptr;
            return b;
        }
        Node* const mx = extremum<true>(a);
        mx->splay();
        assert(mx->child[1] == nullptr);
        mx->child[1] = b;
        mx->parent = nullptr;
        return mx;
    }
    Node* find(const T& key) {
        auto x = root;
        while(x && key != x->value){
            const auto next = x->child[key > x->value];
            if(!next){
                x->splay();
            }
            x = next;
        }
        return x;
    }
    size_t size() const { return n; }
    bool empty() const { return size() == 0; }
    iterator begin() { return iterator{extremum<false>(root)}; }
    iterator end() { return iterator{nullptr}; }
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
