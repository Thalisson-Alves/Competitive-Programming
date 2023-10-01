optional<vector<int>> check_bipartite(const vector<vector<int>> &g) {
  vector<int> color(g.size(), -1);
  color[0] = 0;

  queue<int> q;
  q.push(0);

  while (not q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto x : g[cur]) {
      if (color[x] == color[cur])
        return {};

      if (color[x] == -1) {
        color[x] = color[cur]^1;
        q.push(x);
      }
    }
  }

  return color;
}
