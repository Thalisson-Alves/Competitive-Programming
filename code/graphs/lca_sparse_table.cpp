struct SparseTable {
  int n, b;
  const vector<int> &v;
  vector<int> st, msk;
  static int msb(int x) { return 31-__builtin_clz(x|1); }
  int op(int i, int j) const { return v[i] < v[j] ? i : j; }
  SparseTable(const vector<int> &v_) : n((int)size(v_)), b(msb(n)+1), v(v_), st(n), msk(n) {
    for (int i = 0, at = 0; i < n; msk[i++] = at |= 1) {
      at = (at<<1)&((1<<b)-1);
      while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
    }
    for (int i = 0; i < n/b; i++) st[i] = b*i+b-1-msb(msk[b*i+b-1]);
    for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
      st[n/b*j+i] = op(st[n/b*(j-1)+i], st[n/b*(j-1)+i+(1<<(j-1))]);
  }
  int small(int r, int sz) const { return r-msb(msk[r]&((1<<sz)-1)); }
  int query(int l, int r) const {
    if (r-l+1<=b) return small(r, r-l+1);
    int res = op(small(l+b-1, b), small(r, b));
    int x = l/b+1, y = r/b-1;
    if (x <= y) {
      int j = msb(y-x+1);
      res = op(res, op(st[n/b*j+x], st[n/b*j+y-(1<<j)+1]));
    }
    return res;
  }
};
struct LCA {
  vector<int> inv, pos, dep;
  SparseTable st;
  LCA(const vector<vector<int>> &g, int root = 0) : pos(size(g)), st(tour(g, root)) {}
  vector<int> &tour(const vector<vector<int>> &g, int root) {
    auto dfs = [&](auto &&self, int u, int p, int d) -> void {
      inv.push_back(u), pos[u] = (int)size(dep), dep.push_back(d);
      for (auto v : g[u]) if (v != p) {
        self(self, v, u, d+1);
        inv.push_back(u), dep.push_back(d);
      }
    };
    dfs(dfs, root, -1, 0);
    return dep;
  }
  int lca(int u, int v) const {
    auto [l, r] = minmax(pos[u], pos[v]);
    return inv[st.query(l, r)];
  }
  int dist(int u, int v) const { return dep[pos[u]] + dep[pos[v]] - 2 * dep[pos[lca(u, v)]]; }
};
