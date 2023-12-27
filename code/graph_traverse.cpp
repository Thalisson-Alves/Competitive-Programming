// f :: (cur, cost, prev) -> void
template <typename Graph, typename Container = stack<tuple<typename Graph::Weight, int, int>>>
void traverse(const Graph &g, int start, vector<bool> &vis, const auto f) {
  using Weight = typename Graph::Weight;
  static_assert(std::is_invocable_r_v<void, decltype(f), int, Weight, int>);

  Container q;
  q.emplace(0, start, -1);
  while (not q.empty()) {
    Weight cost; int u, p;
    if constexpr (std::is_same_v<Container, queue<tuple<Weight, int, int>>>)
      tie(cost, u, p) = q.front();
    else
      tie(cost, u, p) = q.top();
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    f(u, cost, p);
    for (auto [v, w] : g.next(u))
      if (not vis[v])
        q.emplace(cost + w, v, u);
  }
}
