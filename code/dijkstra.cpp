// Returns: {dist, prev}
template <typename Graph> auto dijkstra(const Graph &g, int s) {
  using Weight = typename Graph::Weight;
  vector<Weight> dist(g.size(), numeric_limits<Weight>::max());
  vector<int> prev(g.size(), -1);
  dist[s] = 0;
  priority_queue<pair<Weight, int>, vector<pair<Weight, int>>, greater<pair<Weight, int>>> pq;
  pq.emplace(0, s);
  while (not pq.empty()) {
    auto [cost, u] = pq.top(); pq.pop();
    if (cost != dist[u]) continue;

    for (auto [v, w] : g.next(u)) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        pq.emplace(dist[u] + w, v);
      }
    }
  }

  return make_pair(dist, prev);
}
