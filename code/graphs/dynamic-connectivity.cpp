struct UFDS {
  vector<int> ps, sz;
  int comp;
  stack<int> st;
  UFDS(int n = 0) : ps(n), sz(n, 1), comp(n) {
    iota(ps.begin(), ps.end(), 0);
  }
  int find(int x) { return (x == ps[x] ? x : find(ps[x])); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return st.push(-1), false;
    if (sz[x] < sz[y]) swap(x, y);
    st.push(y);
    ps[y] = x;
    sz[x] += sz[y];
    --comp;
    return true;
  }
  void undo() {
    int u = st.top(); st.pop();
    if (u == -1) return;
    sz[ps[u]] -= sz[u];
    ps[u] = u;
    ++comp;
  }
  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++comp;
    return id;
  };
};
vector<int> dynamic_connectivity(int n, vector<array<int, 3>> &qs) {
  unordered_map<ll, int> mp;
  vector<pair<int, int>> edges(size(qs));
  vector<int> final(size(qs), -1);
  for (int i = -1; auto [t, u, v] : qs) {
    ++i;
    if (u > v) swap(u, v);
    if (t == 1) {
      mp[(ll)u*n+v] = i;
      edges[i] = {u, v};
      final[i] = (int)size(qs);
    } else if (t == 0) {
      int id = mp[(ll)u*n+v];
      final[id] = i;
      edges[i] = edges[id];
      final[i] = id;
    }
  }
  vector<int> res(qs.size());
  UFDS ufds(n);
  auto f = [&](auto &&self, int l, int r) -> void {
    if (l >= r) {
      res[l] = ufds.comp;
      return;
    }
    int m = midpoint(l, r), cnt = 1;
    for (int i = m+1; i <= r; i++) if (~final[i] and final[i] <= l)
      ufds.join(edges[i].first, edges[i].second), ++cnt;
    self(self, l, m);
    while (--cnt) ufds.undo();
    for (int i = l; i <= m+1; i++) if (~final[i] and final[i] > r)
      ufds.join(edges[i].first, edges[i].second), ++cnt;
    self(self, m+1, r);
    while (cnt--) ufds.undo();
  };
  f(f, 0, (int)qs.size()-1);
  return res;
}
