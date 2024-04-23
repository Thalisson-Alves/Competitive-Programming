// Returns: {dist, negative cycle}
template <typename Graph> auto bellman_ford(const Graph &g, int s) {
  using Weight = typename Graph::Weight;

  vector<Weight> dist(g.size(), numeric_limits<Weight>::max());
  vector<int> count(g.size());
  vector<bool> in_queue(g.size());
  vector<int> prev(g.size(), -1);
  queue<int> q({s});
  dist[s] = 0;
  count[s] = 1;

  while (not q.empty()) {
    auto u = q.front(); q.pop();
    in_queue[u] = false;
    for (auto [v, w] : g.next(u)) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        if (not in_queue[v]) {
          q.push(v);
          in_queue[v] = true;
          if (++count[v] > g.size()) {
            for (int i = 0; i < g.size(); i++) v = prev[v];

            vector<int> cycle;
            for (int x = v; x != -1; x = prev[x]) {
              cycle.push_back(x);
              if (x == v and cycle.size() > 1)
                break;
            }
            reverse(cycle.begin(), cycle.end());
            return make_pair(dist, cycle);
          }
        }
      }
    }
  }

  return make_pair(dist, vector<int>());
}
