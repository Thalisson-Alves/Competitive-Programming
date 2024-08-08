template <typename T, typename F> struct SegTree {
  int N;
  const T identity = T();
  vector<T> ns;
  const F op;

  SegTree(int n, F f = F(), const T identity_ = T()) : identity(identity_), op(f) {
    N = 1;
    while (N < n) N <<= 1;
    ns.resize(N << 1, identity);
  }
  SegTree(const vector<T> &v, F f = F()) : SegTree((int)v.size(), f) {
    copy(v.begin(), v.end(), ns.begin() + N);
    for (int i = N - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }

  T query(int i) const {
    return ns[i + N];
  }

  T query(int l, int r) const {
    auto ml = identity, mr = identity;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);
    }
    return op(ml, mr);
  }

  int kth(int k) const {
    int i;
    for (i = 1; 2*i < (int)ns.size();) {
      if (ns[2*i] > k) i <<= 1;
      else k -= ns[2*i], i = i*2+1;
    }
    return i-N;
  }

  void update(int i, T value) {
    set(i, op(ns[i + N], value));
  }

  void set(int i, T value) {
    ns[i += N] = value;
    while (i >>= 1)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
};
