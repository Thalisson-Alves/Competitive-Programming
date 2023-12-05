template<size_t Dim> struct GaussianElimination {
  using T = conditional_t<Dim <= 32, uint32_t, uint64_t>;
  vector<T> basis;

  void insert(T x) {
    for (const auto &b : basis)
      x = min(x, x ^ b);
    if (x) basis.push_back(x);
  }

  void merge(const GaussianElimination &other) {
    for (int i = 0; basis.size() < Dim and i < other.size(); i++)
      insert(other.basis[i]);
  }

  void normalize() {
    sort(all(basis));
    for (int i = size() - 1; ~i; --i) {
      for (int j = i - 1; ~j; --j) {
        if (basis[i] & (1ll << (63 - __builtin_clzll(basis[j]))))
          basis[i] ^= basis[j];
      }
    }
  }

  bool check(T x) const {
    for (const auto &b : basis)
      x = min(x, x ^ b);
    return !x;
  }

  auto operator[](T k) const { return at(k); }
  int size() const { return (int) basis.size(); }

  // Need to call normalize() first
  T at(T k) const {
    T ans = 0;
    for (int i = 0; i <= size(); i++) {
      if (k & 1) ans ^= basis[i];
      k >>= 1;
    }
    return ans;
  }

  T max() const {
    T res = 0;
    for (const auto &b : basis)
      res = std::max(res, res ^ b);
    return res;
  }
};
