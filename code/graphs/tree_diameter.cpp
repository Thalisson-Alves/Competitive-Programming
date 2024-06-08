int tree_diameter(const vector<vector<int>> &g, int root=0) {
  vector<int> dist(g.size(), -1);
  int last = root;
  dist[last] = 0;
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto v : g[u]) if (dist[v] == -1) {
      if ((dist[v] = dist[u] + 1) > dist[last])
        last = v;
      self(self, v);
    }
  };
  dfs(dfs, last);

  dist.assign(g.size(), -1);
  dist[last] = 0;
  dfs(dfs, last);

  return dist[last];
}
