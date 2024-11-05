template <typename T, typename F=function<T(T,T)>> struct SparseTable2d {
  template <typename Q> using V = vector<Q>;
  V<V<V<V<T>>>> st;
  F f;
  const T id;
  // Lazy loading constructor. Needs to call build!
  SparseTable2d(F op, const T neutral = T()) : st(), f(op), id(neutral) {}
  SparseTable2d(const V<V<T>> &v, F op = F(), const T neutral = T()) : st(), f(op), id(neutral) { build(v); }
  void build(const V<V<T>> &v) {
    const int n = (int)v.size();
    const int m = (int)v[0].size();
    auto logn = 31-__builtin_clz(n);
    auto logm = 31-__builtin_clz(m);
    st.resize(logn+1, V<V<V<T>>>(n, V<V<T>>(logm+1, V<T>(m))));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) st[0][i][0][j] = v[i][j];
      for (int lj = 1; lj <= logm; lj++) for (int j = 0; j+(1<<(lj-1)) < m; j++)
        st[0][i][lj][j] = f(st[0][i][lj-1][j], st[0][i][lj-1][j+(1<<(lj-1))]);
    }
    for (int li = 1; li <= logn; li++) for (int i = 0; i+(1<<(li-1)) < n; i++)
      for (int lj = 0; lj <= logm; lj++) for (int j = 0; j < m; j++)
        st[li][i][lj][j] = f(st[li-1][i][lj][j], st[li-1][i+(1<<(li-1))][lj][j]);
  }
  T query(int x1, int y1, int x2, int y2) const {
    if (x1 > x2 or y1 > y2) return id;
    auto lx = 31-__builtin_clz(x2-x1+1);
    auto ly = 31-__builtin_clz(y2-y1+1);
    return f(
      f(st[lx][x1][ly][y1], st[lx][x1][ly][y2+1-(1<<ly)]),
      f(st[lx][x2+1-(1<<lx)][ly][y1], st[lx][x2+1-(1<<lx)][ly][y2+1-(1<<ly)])
    );
  }
};
