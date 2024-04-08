vector<pair<int, int>> tree_flatten(const vector<vector<int>> &g, int root = 0) {
  vector<int> pre;
  pre.reserve(g.size());
  vector<pair<int, int>> flat(g.size());
  int timer = -1;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    ++timer;
    pre.push_back(u);
    for (auto v : g[u]) if (v != p) {
      self(self, v, u);
    }
    flat[u].second = timer;
  };
  dfs(dfs, root, -1);
  for (int i = 0; i < (int)g.size(); i++)
    flat[pre[i]].first = i;
  return flat;
}
