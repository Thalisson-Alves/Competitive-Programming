// Returns: {dist, prev}
template <typename Graph> auto dijkstra(const Graph &g, int s) {
  vector<ll> dist(g.size(), numeric_limits<ll>::max());
  vector<int> prev(g.size(), -1);
  dist[s] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);
  while (not pq.empty()) {
    auto [cost, u] = pq.top(); pq.pop();
    if (cost != dist[u]) continue;

    for (auto [v, w] : g[u].weighted()) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        pq.emplace(dist[u] + w, v);
      }
    }
  }

  return make_pair(dist, prev);
}
