void graph_cycles(const vector<vector<int>> &g, int u, int p, vector<int> &ps, vector<int> &color, int &cn, vector<vector<int>> &cycles)
{
  if (color[u] == 2) {
    return;
  }

  if (color[u] == 1) {
    cn++;
    int cur = p;
    cycles.emplace_back();
    auto &v = cycles.back();
    v.push_back(cur);
    while (cur != u) {
      cur = ps[cur];
      v.push_back(cur);
    }
    return;
  }

  ps[u] = p;
  color[u] = 1;
  for (auto v : g[u]) {
    if (v == ps[u]) continue;
    graph_cycles(g, v, u, ps, color, cn, cycles);
  }

  color[u] = 2;
}

vector<vector<int>> graph_cycles(const vector<vector<int>> &g, int u) {
  vector<int> ps(g.size(), -1), color(g.size());
  int cn = 0;
  vector<vector<int>> cycles;
  graph_cycles(g, u, -1, ps, color, cn, cycles);
  return cycles;
}
