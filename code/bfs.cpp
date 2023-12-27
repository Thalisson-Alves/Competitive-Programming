// Returns: {dist, prev}
template <typename Graph> auto bfs(const Graph &g, int s) {
  using Weight = typename Graph::Weight;
  vector<Weight> dist(g.size(), numeric_limits<Weight>::max());
  vector<int> prev(g.size(), -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (not q.empty()) {
    auto u = q.front(); q.pop();
    for (auto [v, w] : g.next(u)) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        q.push(v);
      }
    }
  }

  return make_pair(dist, prev);
}
