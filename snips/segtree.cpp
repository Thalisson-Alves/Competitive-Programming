template <typename T, T neutral = T(), typename operation_t = T (*)(T, T)>
struct SegTree {
  int N;
  vector<T> ns;
  operation_t operation;

  SegTree(int n, operation_t op) : N(n), ns(2 * N, neutral), operation(op) {}

  SegTree(const vector<T> &v, operation_t op) : SegTree((int)v.size(), op) {
    copy(v.begin(), v.end(), ns.begin() + N);

    for (int i = N - 1; i > 0; --i)
      ns[i] = operation(ns[2 * i], ns[2 * i + 1]);
  }

  T RQ(size_t l, size_t r) {
    auto a = l + N, b = r + N;
    auto ans = neutral;

    while (a <= b) {
      if (a & 1)
        ans = operation(ans, ns[a++]);
      if (not(b & 1))
        ans = operation(ans, ns[b--]);

      a /= 2;
      b /= 2;
    }

    return ans;
  }

  void update(size_t i, T value) {
    update_set(i, operation(ns[i + N], value));
  }

  void update_set(size_t i, T value) {
    auto a = i + N;

    ns[a] = value;
    while (a >>= 1)
      ns[a] = operation(ns[2 * a], ns[2 * a + 1]);
  }
};
