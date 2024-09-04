void small_to_large(const vector<vector<int>> &g, auto &&add, auto &&rem, auto &&ans, int root=0) {
  vector<int> sz(size(g)), pre(size(g)), path(size(g)), pos(size(g));
  int timer = -1;
  auto tour = [&](auto &&self, int u, int p) -> void {
    pre[u] = ++timer;
    path[pre[u]] = u;
    for (auto v : g[u]) if (v != p) self(self, v, u);
    pos[u] = timer;
    sz[u] = pos[u] - pre[u] + 1;
  };
  tour(tour, root, -1);
  auto dfs = [&](auto &&self, int u, int p = -1, bool keep=true) -> void {
    int mx = -1;
    for (auto v : g[u]) {
      if (v != p and (mx == -1 or sz[mx] < sz[v]))
        mx = v;
    }
    for (auto v : g[u]) if (v != p and v != mx) self(self, v, u, false);
    if (mx != -1) self(self, mx, u, true);
    add(u);
    for (auto v : g[u]) if (v != p and v != mx) {
      for (int i = pre[v]; i <= pos[v]; i++)
        add(path[i]);
    }
    ans(u);
    if (!keep) for (int i = pre[u]; i <= pos[u]; i++) rem(path[i]);
  };
  dfs(dfs, root);
}
