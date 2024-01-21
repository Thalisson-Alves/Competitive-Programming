optional<vector<int>> check_bipartite(const vector<vector<int>> &g) {
  vector<int> color(g.size(), -1);
  for (int i = 0; i < (int)g.size(); i++) {
    if (color[i] != -1) continue;
    color[i] = 0;

    queue<int> q;
    q.push(i);

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
  }
  for (auto &x : color) if (x == -1) x = 0;
  return color;
}
