template <typename Graph> void cycles(const Graph &g, auto &&f) {
  // If `f` returns true then the search is stopped.
  static_assert(std::is_invocable_r_v<bool, decltype(f), const vector<int> &>);

  vector<int> ps(g.size(), -1), color(g.size());
  vector<vector<int>> cycles;
  auto dfs = [&](auto &&self, int u, int p) -> bool {
    if (color[u] == 2) return false;

    if (color[u] == 1) {
      int cur = p;
      vector<int> cy;
      cy.push_back(cur);
      while (cur != u) {
        cur = ps[cur];
        cy.push_back(cur);
      }
      reverse(all(cy));
      return f(cy);
    }

    ps[u] = p;
    color[u] = 1;
    for (auto [v, _] : g[u]) {
      if ((Graph::is_directed() or v != p) and self(self, v, u))
        return true;
    }

    color[u] = 2;
    return false;
  };

  for (int i = 0; i < (int)g.size(); i++)
    if (dfs(dfs, i, -1)) return;
}
template <typename Graph> vector<int> find_cycle(const Graph &g) {
  vector<int> found;
  cycles(g, [&found](const vector<int> &cycle) {
    found = cycle;
    return true;
  });
  return found;
}
template <typename Graph> bool check_cycle(const Graph &g) {
  bool found = false;
  cycles(g, [&found](const vector<int> &) {
    found = true;
    return true;
  });
  return found;
}
