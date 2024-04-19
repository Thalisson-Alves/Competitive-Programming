template <typename Graph> auto bfs(const Graph &g, int s) {
  vector<int> dist(g.size(), numeric_limits<int>::max());
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (not q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : g[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return dist;
}
