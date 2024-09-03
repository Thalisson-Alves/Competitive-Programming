#define F(exp) [](auto a, auto b) { return exp; }
template <typename T, typename Op = T(*)(T,T)> struct SparseSegTree {
  struct Node {
    T value;
    unique_ptr<Node> l, r;
  };
  unique_ptr<Node> root;
  const Op op;
  const T id;
  const pair<int, int> range;
  SparseSegTree(int l, int r, Op f = Op(), T id_ = T()) : root(make_unique<Node>(id_)), op(f), id(id_), range(l, r) { }
  T query(int idx) { return query(idx, idx); }
  T query(int l, int r) { return query(root, l, r, range.first, range.second); }
  int pos(const auto &f) {
    if (!f(root->value)) return -1;
    return pos(root, range.first, range.second, f, id);
  }
private:
  T query(unique_ptr<Node> &node, int l, int r, int tl, int tr) {
    if (r < tl or tr < l) return id;
    if (l <= tl and tr <= r) return node->value;
    extend(node);
    auto tm = tl + (tr - tl) / 2;
    return op(query(node->l, l, r, tl, tm), query(node->r, l, r, tm+1, tr));
  }
  int pos(unique_ptr<Node> &node, int tl, int tr, const auto &f, T acc) {
    if (tl == tr) return tl;
    extend(node);
    auto tm = tl + (tr - tl) / 2;
    if (f(op(acc, node->l->value))) return pos(node->l, tl, tm, f, acc);
    return pos(node->r, tm+1, tr, f, op(acc, node->l->value));
  }
public:
  void set(int idx, const T x) { update<1>(root, idx, x, range.first, range.second); }
  void update(int idx, const T x) { update<0>(root, idx, x, range.first, range.second); }
private:
  template<bool is_setting> void update(unique_ptr<Node> &node, int idx, const T x, int tl, int tr) {
    if (tl == tr) {
      if constexpr (is_setting) node->value = x;
      else node->value = op(node->value, x);
      return;
    }
    extend(node);
    auto tm = tl + (tr - tl) / 2;
    (idx <= tm
     ? update<is_setting>(node->l, idx, x, tl, tm)
     : update<is_setting>(node->r, idx, x, tm+1, tr));
    node->value = op(node->l->value, node->r->value);
  }
  void extend(unique_ptr<Node> &node) {
    if (node->l) return;
    (node->l = make_unique<Node>())->value = id;
    (node->r = make_unique<Node>())->value = id;
  }
};
