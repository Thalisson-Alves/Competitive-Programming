/* Min Cost Flow
 *
 * Calculates the minimum cost flow in a graph.
 *
 * Methods:
 * - MinCostFlow(n): initializes the data structures for a graph with n vertices.
 *   - O(n)
 * - add_edge(u, v, cap, cost): adds an edge between vertices u and v with capacity `cap` and cost `cost`.
 *   - O(1)
 * - flow(s, t, flow_limit): calculates the minimum cost flow from vertex `s` to vertex `t` with flow limit `flow_limit`. - O(V * E * f), where f is the flow limit
 * - paths(s, t): returns the nodes used on paths of the minimum cost flow from vertex `s` to vertex `t`.
 *   - O((V + E) * f), where f is the flow limit used in the flow method
 */
template <typename Cap, typename Cost> struct MinCostFlow {
  struct Edge {
    int to;
    Cap cap, cap_used;
    Cost cost;
  };
  int n;
  vector<Edge> e;
  vector<vector<int>> g;
  MinCostFlow() {}
  MinCostFlow(int n_) : n(n_), g(n) {}
  void add_edge(int u, int v, Cap cap, Cost cost) {
    assert(u < (int)g.size());
    assert(v < (int)g.size());
    g[u].push_back((int)e.size());
    e.emplace_back(v, cap, 0, cost);
    g[v].push_back((int)e.size());
    e.emplace_back(u, 0, 0, -cost);
  }
  // {flow, cost}
  pair<Cap, Cost> flow(int s, int t, Cap flow_limit = numeric_limits<Cap>::max()) {
    vector<pair<Cost, Cost>> dist(n);
    vector<int> pre(n);
    vector<bool> vis(n);
    auto min_path = [&]() {
      for (int i = 0; i < n; i++) {
        dist[i].second = numeric_limits<Cost>::max();
        pre[i] = -1;
        vis[i] = 0;
      }
      dist[s].second = 0;
      using PQ = pair<Cost, int>;
      vector<pair<Cost, int>> qmin({{0, s}});
      priority_queue<PQ, vector<PQ>, greater<PQ>> pq;
      while (size(qmin) or size(pq)) {
        Cost cost; int u;
        if (size(qmin)) {
          tie(cost, u) = qmin.back();
          qmin.pop_back();
        } else {
          tie(cost, u) = pq.top();
          pq.pop();
        }
        if (vis[u]) continue;
        vis[u] = 1;
        if (u == t) break;
        for (auto i : g[u]) {
          auto [v, cap, _, w] = e[i];
          if (!cap) continue;
          auto new_dist = w - dist[v].first + dist[u].first;
          if (dist[v].second-dist[u].second > new_dist) {
            new_dist += dist[u].second;
            dist[v].second = new_dist;
            pre[v] = i;
            if (dist[v] == dist[u]) qmin.emplace_back(new_dist, v);
            else pq.emplace(new_dist, v);
          }
        }
      }
      if (!vis[t]) return false;
      for (int i = 0; i < n; i++) {
        if (vis[i])
          dist[i].first -= dist[t].second - dist[i].second;
      }
      return true;
    };
    Cap flow = 0; Cost cost = 0;
    while (flow < flow_limit and min_path()) {
      Cap aug = numeric_limits<int>::max();
      for (int i = t; i != s; i = e[pre[i] ^ 1].to)
        aug = min({flow_limit - flow, aug, e[pre[i]].cap});
      for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap -= aug;
        e[pre[i] ^ 1].cap += aug;
        e[pre[i]].cap_used += aug;
        e[pre[i] ^ 1].cap_used -= aug;
      }
      flow += aug;
      cost += aug * dist[t].first;
    }
    return {flow, cost};
  }
  // Needs to be called after flow method
  vector<vector<int>> paths(int s, int t) {
    vector<vector<int>> p;
    do {
      int cur = s;
      auto &res = p.emplace_back();
      res.push_back(cur);
      while (cur != t) {
        bool found = false;
        for (auto i : g[cur]) {
          auto &[v, _, cap_used, cost] = e[i];
          if (cap_used > 0) {
            --cap_used;
            res.push_back(cur = v);
            found = true;
            break;
          }
        }
        if (!found) break;
      }
    } while (p.back().back() == t);
    p.pop_back();
    return p;
  }
};
