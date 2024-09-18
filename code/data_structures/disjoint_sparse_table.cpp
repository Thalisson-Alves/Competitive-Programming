template <typename T, typename Op = T(*)(T,T)> struct DisjointSparseTable {
  vector<vector<T>> st;
  Op f;
  const T identity;
  // Lazy loading constructor. Needs to call build!
  DisjointSparseTable(Op op, const T neutral = T()) : st(), f(op), identity(neutral) {}
  DisjointSparseTable(const vector<T> &v, Op op = Op(), const T neutral = T()) : st(), f(op), identity(neutral) {
    build(v);
  }
  void build(vector<T> v) {
    const int sz = (31 - __builtin_clz((int)size(v))) + 1;
    st.resize(sz, vector<T>(1ll << sz));
    v.resize(st[0].size(), identity);
    for (int level = 0; level < (int)st.size(); ++level) {
      for (int block = 0; block < (1 << level); ++block) {
        const auto l = block << (st.size() - level);
        const auto r = (block + 1) << (st.size() - level);
        const auto m = l + (r - l) / 2;
        st[level][m] = v[m];
        for (int i = m + 1; i < r; i++) st[level][i] = f(st[level][i-1], v[i]);
        st[level][m-1] = v[m-1];
        for (int i = m-2; i >= l; i--) st[level][i] = f(st[level][i+1], v[i]);
      }
    }
  }
  T query(int l, int r) const {
    if (l > r) return identity;
    if (l == r) return st.back()[l];
    const auto k = 31 - __builtin_clz(l^r);
    const auto level = (int)st.size() - 1 - k;
    return f(st[level][l], st[level][r]);
  }
};
