template <typename Undigraph> void find_articulations(const Undigraph &g, auto &&f) {
  static_assert(std::is_invocable_r_v<void, decltype(f), int>);

  vector<int> tin(g.size()), tout(g.size()), low(g.size());
  int timer = 1;

  auto dfs = [&](auto &&self, int u, int p) -> void {
    tin[u] = low[u] = timer++;
    int cnt = 0;

    for (auto v : g[u]) if (v != p) {
      if (tin[v]) {
        low[u] = min(low[u], tin[v]);
      } else {
        self(self, v, u);
        low[u] = min(low[u], low[v]);
        ++cnt;
        if (~p and low[v] >= tin[u]) {
          f(u);
        }
      }
    }

    if (p == -1 and cnt > 1) f(u);
  };

  for (int i = 0; i < (int)g.size(); i++) {
    if (!tin[i])
      dfs(dfs, i, -1);
  }
}
