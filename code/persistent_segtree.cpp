#define F(exp) [](auto a, auto b) { return exp; }
template <typename T, auto op, size_t Size=0x989680>
struct PersistentSegTree {
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
  const int N;
  vector<int> roots;

  PersistentSegTree(int n, T id = T()) : identity(id), N(n) {
    nodes[0].value = identity;
  }
  PersistentSegTree(const vector<T> &v, T id = T()) : PersistentSegTree((int)v.size(), id) {
    roots.push_back(build(v, 0, N-1));
  }

  T query(int time, int idx) { return query(time, idx, idx); }
  T query(int time, int l, int r) {
    assert(time < (int)roots.size());
    return query(nodes[roots[time]], l, r, 0, N-1);
  }
  int set(int time, int idx, const T x) {
    assert(time < (int)roots.size());
    roots.push_back(update<1>(nodes[roots[time]], idx, x, 0, N-1));
    return (int)roots.size() - 1;
  }
  int update(int time, int idx, const T x) {
    assert(time < (int)roots.size());
    roots.push_back(update<0>(nodes[roots[time]], idx, x, 0, N-1));
    return (int)roots.size() - 1;
  }
  int build(const vector<T> &v, int tl, int tr) {
    if (tl == tr) {
      nodes[cur_pos++].value = v[tl];
      return cur_pos-1;
    }
    auto tm = tl + (tr - tl) / 2;
    return newchild(build(v, tl, tm), build(v, tm+1, tr));
  }

private:
  T query(Node &node, int l, int r, int tl, int tr) {
    if (r < tl or tr < l)
      return identity;

    if (l <= tl and tr <= r) {
      return node.value;
    }

    auto tm = tl + (tr - tl) / 2;
    return op(query(nodes[node.left_child], l, r, tl, tm), query(nodes[node.right_child], l, r, tm+1, tr));
  }
  template<bool is_setting> int update(const Node &node, int idx, const T x, int tl, int tr) {
    if (tl == tr) {
      if constexpr (is_setting) {
        nodes[cur_pos++].value = x;
      } else {
        nodes[cur_pos++].value = op(node.value, x);
      }
      return cur_pos-1;
    }

    auto tm = tl + (tr - tl) / 2;
    return (idx <= tm
     ? newchild(update<is_setting>(nodes[node.left_child], idx, x, tl, tm), node.right_child)
     : newchild(node.left_child, update<is_setting>(nodes[node.right_child], idx, x, tm+1, tr)));
  }

  int newchild(int left_child, int right_child) const {
    auto &node = nodes[cur_pos++];
    node.left_child = left_child;
    node.right_child = right_child;

    node.value = op(nodes[left_child].value, nodes[right_child].value);
    return cur_pos-1;
  }
};
template <typename T, auto op, size_t Size> PersistentSegTree<T, op, Size>::Node PersistentSegTree<T, op, Size>::nodes[Size];
template <typename T, auto op, size_t Size> int PersistentSegTree<T, op, Size>::cur_pos = 1;
