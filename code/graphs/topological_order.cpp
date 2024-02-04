vector<int> topological_order(const vector<vector<int>> &g) {
  vector<char> vis(g.size());
  vector<int> order;
  order.reserve(g.size());
  auto dfs = [&](auto &&self, int u) -> void {
    vis[u] = true;
    for (auto v : g[u])
      if (not vis[v])
        self(self, v);
    order.push_back(u);
  };

  for (auto i = 0; i < (int)g.size(); i++)
    if (not vis[i])
      dfs(dfs, i);

  reverse(order.begin(), order.end());
  return order;
}
