mt19937 rng((long) chrono::steady_clock::now().time_since_epoch().count());
template <typename T> struct Treap {
  struct Node {
    T key;
    int priority, size;
    Node *l, *r;
    Node(T value, int prior) : key(value), priority(prior), size(1), l(), r() {}
    Node(T value) : Node(value, (int)rng()) {}
    ~Node() { delete l; delete r; }
    void update() {
      size = 1;
      if (l) size += l->size;
      if (r) size += r->size;
    }
  };
  using ptr = Node*;
  ptr root;
  Treap() : root() {}
  Treap(const Treap &o) = delete;
  ~Treap() { delete root; }
  int size(ptr t) const { return (t ? t->size : 0); }
  int size() const { return size(root); }
  ptr merge(ptr l, ptr r) {
    if (!l or !r) return l ? l : r;
    if (l->priority > r -> priority) return l->r = merge(l->r, r), l->update(), l;
    else return r->l = merge(l, r->l), r->update(), r;
  }
  pair<ptr, ptr> split(ptr t, int pos) {
    if (!t) return {nullptr, nullptr};
    pair<ptr, ptr> res;
    if (size(t->l) >= pos) res = split(t->l, pos), t->l = res.second, res = {res.first, t};
    else res = split(t->r, pos-size(t->l)-1), t->r = res.first, res = {t, res.second};
    t->update();
    return res;
  }
  T get(int pos) {
    auto p1 = split(root, pos);
    auto p2 = split(p1.second, 1);
    auto res = p2.first->key;
    root = merge(merge(p1.first, p2.first), p2.second);
    return res;
  }
  void set(int pos, T s) {
    auto p1 = split(root, pos);
    auto p2 = split(p1.second, 1);
    p2.first->key = s;
    p2.first->update();
    root = merge(merge(p1.first, p2.first), p2.second);
  }
  void insert(int pos, T value) {
    auto p = split(root, pos);
    ptr node = new Node(value);
    root = merge(merge(p.first, node), p.second);
  }
  void push_back(T value) { root = merge(root, new Node(value)); }
  void remove(int pos) {
    auto p1 = split(root, pos);
    auto p2 = split(p1.second, 1);
    root = merge(p1.first, p2.second);
  }
};
