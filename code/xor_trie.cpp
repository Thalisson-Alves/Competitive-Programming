template <typename T=ll> struct XorTrie {
  struct Node {
    T value;
    array<shared_ptr<Node>, 2> children;
 
    Node() : value(), children() {
      for (auto &x : children)
        x = shared_ptr<Node>(nullptr);
    }
  };
 
  shared_ptr<Node> root;
 
  XorTrie() : root(make_shared<Node>()) {}
 
  static constexpr int tsize() {
    if constexpr (is_same_v<int, T>) {
      return 31;
    } else {
      return 63;
    }
  }
 
  void insert(T x) {
    auto cur = root;
    for (int i = tsize(); ~i; --i) {
      auto &child = cur->children[x>>i&1];
      if (!child)
        child = make_shared<Node>();
      cur = child;
    }
    cur->value = x;
  }
 
  T query(T x) const {
    T res = 0;
    auto cur = root;
    for (int i = tsize(); ~i; --i) {
      int idx = x>>i&1;
 
      if (cur->children[idx^1]) {
        cur = cur->children[idx^1];
        res |= (T)1 << i;
      } else if (cur->children[idx]) {
        cur = cur->children[idx];
      }
    }
    return res;
  }
};
