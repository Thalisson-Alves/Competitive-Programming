template <typename T, typename Op = T(*)(T,T)> struct SparseTable {
  vector<vector<T>> st;
  Op f;
  const T id;
  // Lazy loading constructor. Needs to call build!
  SparseTable(Op op, const T neutral = T()) : st(), f(op), id(neutral) {}
  SparseTable(const vector<T> &v, Op op = Op(), const T neutral = T()) : st(), f(op), id(neutral) { build(v); }
  void build(const vector<T> &v) {
    auto logn = 31-__builtin_clz((int)size(v));
    st.resize(logn+1, vector<T>(v.size()));
    st[0] = v;
    for (int i = 1; i <= logn; i++)
      for (int j = 0; j + (1 << i) <= (int)v.size(); j++)
        st[i][j] = f(st[i-1][j], st[i-1][j+(1 << (i-1))]);
  }
  T query(int l, int r) const {
    if (l > r) return id;
    auto lg = 31-__builtin_clz(r-l+1);
    return f(st[lg][l], st[lg][r-(1<<lg)+1]);
  }
  // Non RMQ query
  T query_complete(int l, int r) const {
    if (l > r) return id;
    T acc = id;
    for (int i = 31-__builtin_clz(size(st[0])); ~i; --i)
      if ((1 << i) <= r - l + 1) {
        acc = f(acc, st[i][l]);
        l += 1 << i;
      }
    return acc;
  }
};
