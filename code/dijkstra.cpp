vector<ll> dijkstra(const vector<vector<pair<int, ll>>> &g, int s)
{
  vector<ll> min_cost(g.size(), LLONG_MAX);
  min_cost[s] = 0;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);

  while (not pq.empty())
  {
    auto [cost, cur] = pq.top(); pq.pop();
    if (cost != min_cost[cur]) continue;

    for (auto [x, y] : g[cur])
    {
      auto new_cost = min_cost[cur] + y;
      if (new_cost < min_cost[x])
      {
        min_cost[x] = new_cost;
        pq.emplace(new_cost, x);
      }
    }
  }

  return min_cost;
}
