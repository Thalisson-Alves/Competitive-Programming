constexpr int m1 = 1e9+7, m2 = 1e9+9;
auto dijkstra = [&](int s) {
  vector<ll> dist(n, numeric_limits<ll>::max());
  dist[s] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);
  vector<pair<ll, ll>> ways(n, {0,0});
  ways[s] = {1, 1};
  while (not pq.empty()) {
    auto [cost, u] = pq.top(); pq.pop();
    if (cost != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.emplace(dist[u] + w, v);
        ways[v] = ways[u];
      } else if (dist[v] == dist[u] + w) {
        (ways[v].first += ways[u].first) %= m1;
        (ways[v].second += ways[u].second) %= m2;
      }
    }
  }
  return make_pair(dist, ways);
};
