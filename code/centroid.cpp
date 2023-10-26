int centroid(const vector<vector<int>> &g, int root=0) {
  vector<int> sz(g.size());
  {
    auto dfs = [&sz, &g](auto&& self, int u, int p) -> void {
      sz[u] = 1;
      for (auto x : g[u]) if (x != p) {
        self(self, x, u);
        sz[u] += sz[x];
      }
    };
    dfs(dfs, root, -1);
  }

  const int max_sz = (int)g.size() >> 1;
  int cur = root, prev = -1;
  for (;;) {
    bool ok = true;
    for (auto x : g[cur]) if (x != prev) {
      if (sz[x] > max_sz) {
        prev = cur;
        cur = x;
        ok = false;
        break;
      }
    }

    if (ok) break;
  }

  return cur;
}
