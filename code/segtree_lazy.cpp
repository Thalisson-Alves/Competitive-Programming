template <typename T> struct SegTree {
  int N;
  vector<T> v, lazy;

  SegTree(int n) : N(n), v(4 * N), lazy(4 * N) {}
  SegTree(const vector<T> &xs) : N((int)xs.size()), v(4 * N), lazy(4 * N, 0) {
    for (int i = 0; i < N; i++)
      update(i, xs[i]);
  }

  void update(int i, T value) { update(i, i, value); }
  void update(int a, int b, T value) { update(1, 0, N - 1, a, b, value); }
  T query(int a, int b) { return query(1, 0, N - 1, a, b); }
  T query(int i) { return query(1, 0, N - 1, i, i); }

private:
  void apply_propagation(int node, int l, int r) {
    v[node] += (r - l + 1) * lazy[node];
    propagate(node, l, r, lazy[node]);
    lazy[node] = 0;
  }

  void propagate(int node, int l, int r, T value) {
    if (l >= r)
      return;

    lazy[2 * node] += value;
    lazy[2 * node + 1] += value;
  }

  void update(int node, int l, int r, int a, int b, T value) {
    if (lazy[node])
      apply_propagation(node, l, r);

    if (a > r or b < l)
      return;

    if (a <= l and b >= r) {
      v[node] += (r - l + 1) * value;
      propagate(node, l, r, value);
      return;
    }

    auto m = l + (r - l) / 2;
    update(2 * node, l, m, a, b, value);
    update(2 * node + 1, m + 1, r, a, b, value);

    v[node] = v[2 * node] + v[2 * node + 1];
  }

  T query(int node, int l, int r, int a, int b) {
    if (lazy[node])
      apply_propagation(node, l, r);

    if (a > r or b < l)
      return 0;

    if (a <= l and b >= r)
      return v[node];

    auto m = l + (r - l) / 2;
    auto x = query(2 * node, l, m, a, b);
    auto y = query(2 * node + 1, m + 1, r, a, b);
    return x + y;
  }
};
