#define F(exp) [](auto a, auto b) { return exp; }
template <typename T, auto op, size_t Size=0x989680>
struct SparseSegTree {
  static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                "Operation must be convertible to std::function<T(T, T)>");

  struct Node {
    T value;
    int left_child, right_child;
    int left_index, right_index;

    Node() : value(T()), left_child(0), right_child(0), left_index(0), right_index(0) {}
    inline void init(const T x, int l, int r) {
      value = x;
      left_index = l;
      right_index = r;
    }
  };

  static int cur_pos;
  static Node nodes[Size];
  const T identity;

  SparseSegTree(int l, int r, T id = T()) : identity(id) {
    nodes[0].init(id, l, r);
  }

  T query(int idx) { return query(idx, idx); }
  T query(int l, int r) { return query(nodes[0], l, r); }

  T query(Node &node, int l, int r) {
    if (r < node.left_index or node.right_index < l)
      return identity;

    if (l <= node.left_index and node.right_index <= r) {
      return node.value;
    }

    extend(node);
    return op(query(nodes[node.left_child], l, r), query(nodes[node.right_child], l, r));
  }

  void set(int idx, const T x) { update<1>(nodes[0], idx, x); }
  void update(int idx, const T x) { update<0>(nodes[0], idx, x); }
  template<bool is_setting> void update(Node &node, int idx, const T x) {
    if (node.left_index == node.right_index) {
      if constexpr (is_setting) {
        node.value = x;
      } else {
        node.value = op(node.value, x);
      }
      return;
    }

    extend(node);
    auto &left = nodes[node.left_child];
    auto &right = nodes[node.right_child];
    update<is_setting>((idx <= left.right_index ? left : right), idx, x);
    node.value = op(left.value, right.value);
  }

private:
  void extend(Node &node) {
    if (node.left_child) return;
    assert(cur_pos < (int)Size);
    auto mid = node.left_index + (node.right_index - node.left_index) / 2;
    nodes[node.left_child = cur_pos++].init(identity, node.left_index, mid);
    nodes[node.right_child = cur_pos++].init(identity, mid + 1, node.right_index);
  }
};
template <typename T, auto op, size_t Size> SparseSegTree<T, op, Size>::Node SparseSegTree<T, op, Size>::nodes[Size];
template <typename T, auto op, size_t Size> int SparseSegTree<T, op, Size>::cur_pos = 1;
