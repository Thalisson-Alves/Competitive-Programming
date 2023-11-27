#define F(exp) [](auto a, auto b) { return exp; }
template <typename T, auto op, size_t Size=0x989680>
struct SparseSegTree {
  static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                "Operation must be convertible to std::function<T(T, T)>");

  struct Node {
    T value;
    int left_child, right_child;

    Node() : value(T()), left_child(0), right_child(0) {}
  };

  static int cur_pos;
  static Node nodes[Size];
  const T identity;
  const pair<int, int> range;

  SparseSegTree(int l, int r, T id = T()) : identity(id), range(l, r) { }

  T query(int idx) { return query(idx, idx); }
  T query(int l, int r) { return query(nodes[0], l, r, range.first, range.second); }

private:
  T query(Node &node, int l, int r, int tl, int tr) {
    if (r < tl or tr < l)
      return identity;

    if (l <= tl and tr <= r) {
      return node.value;
    }

    extend(node);
    auto tm = tl + (tr - tl) / 2;
    return op(query(nodes[node.left_child], l, r, tl, tm), query(nodes[node.right_child], l, r, tm+1, tr));
  }

public:
  void set(int idx, const T x) { update<1>(nodes[0], idx, x, range.first, range.second); }
  void update(int idx, const T x) { update<0>(nodes[0], idx, x, range.first, range.second); }

private:
  template<bool is_setting> void update(Node &node, int idx, const T x, int tl, int tr) {
    if (tl == tr) {
      if constexpr (is_setting) {
        node.value = x;
      } else {
        node.value = op(node.value, x);
      }
      return;
    }

    extend(node);
    auto tm = tl + (tr - tl) / 2;
    (idx <= tm
     ? update<is_setting>(nodes[node.left_child], idx, x, tl, tm)
     : update<is_setting>(nodes[node.right_child], idx, x, tm+1, tr));
    node.value = op(nodes[node.left_child].value, nodes[node.right_child].value);
  }

  void extend(Node &node) {
    if (node.left_child) return;
    assert(cur_pos < (int)Size);
    nodes[node.left_child = cur_pos++].value = identity;
    nodes[node.right_child = cur_pos++].value = identity;
  }
};
template <typename T, auto op, size_t Size> SparseSegTree<T, op, Size>::Node SparseSegTree<T, op, Size>::nodes[Size];
template <typename T, auto op, size_t Size> int SparseSegTree<T, op, Size>::cur_pos = 1;
