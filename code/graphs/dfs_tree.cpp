enum class EdgeType {
  TREE = 1,
  FORWARD,
  CROSS,
  BACK,
};
template <typename Graph> void dfs_tree(const Graph &g, auto f) {
  static_assert(std::is_invocable_r_v<void, decltype(f), int, int, EdgeType>);

  vector<bool> vis(g.edges.size());
  vector<int> tin(g.size()), tout(g.size());
  int timer = 1;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    tin[u] = timer++;
    for (auto id : g.g[u]) if (!vis[id]) {
      vis[id] = 1;

      auto [from, to, _] = g.edges[id];
      int v = from ^ to ^ u;

      if (v == p) continue;

      if (!tin[v]) {
        self(self, v, u);
        f(u, v, EdgeType::TREE);
      } else if (tin[v] < tin[u]) {
        f(u, v, (tout[v] ? EdgeType::CROSS : EdgeType::BACK));
      } else {
        f(u, v, EdgeType::FORWARD);
      }
    }
    tout[u] = timer++;
  };

  for (int u = 0; u < g.size(); u++) {
    if (!tin[u]) dfs(dfs, u, -1);
  }
}
