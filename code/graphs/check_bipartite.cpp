template <typename Graph> bool check_bipartite(const Graph &g, int u, vector<int> &color) {
  assert((int)color.size() >= g.size());
  color[u] = 0;
  queue<int> q;
  q.push(u);
  while (not q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto [x, _] : g[cur]) {
      if (color[x] == color[cur]) return false;
      if (color[x] == -1) {
        color[x] = color[cur]^1;
        q.push(x);
      }
    }
  }
  return true;
}
template <typename Graph> vector<int> check_bipartite(const Graph &g) {
  vector<int> color(g.size(), -1);
  for (int i = 0; i < g.size(); i++) {
    if (color[i] != -1) continue;
    if (!check_bipartite(g, i, color)) return {};
  }
  for (auto &x : color) if (x == -1) x = 0;
  return color;
}
