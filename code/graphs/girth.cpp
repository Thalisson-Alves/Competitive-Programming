/* Graph Girth
 *
 * Given an undirected graph, the girth of the graph is the length of the
 * shortest cycle in the graph. If the graph is acyclic, the girth is infinity.
 *
 * Time complexity: O(V * E)
 */
template <typename Undigraph> int girth(const Undigraph &g) {
  int res = INT_MAX;
  auto loop_size = [&](int u) -> void {
    vector<pair<int, int>> q({{u, -1}});
    q.reserve(g.size());
    vector<int> dist(g.size(), -1);
    dist[u] = 0;
    for (int i = 0; i < (int)q.size(); i++) {
      auto [cur, par] = q[i];
      if (2*dist[cur] >= res) return;
      for (auto x : g[cur]) if (x != par) {
        if (~dist[x]) {
          res = min(res, dist[x] + dist[cur] + 1);
        } else {
          dist[x] = dist[cur] + 1;
          q.emplace_back(x, cur);
        }
      }
    }
  };

  vector<short> vis(g.size());
  auto mark_cycle = [&](int u) -> void {
    queue<int> q({u});
    vis[u] = 1;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto v : g[cur]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        } else {
          vis[v] = 2;
        }
      }
    }
  };

  for (int i = 0; i < (int)g.size(); i++) if (!vis[i]) mark_cycle(i);
  for (int i = 0; i < (int)g.size(); i++) if (vis[i] == 2) loop_size(i);
  return res;
}
