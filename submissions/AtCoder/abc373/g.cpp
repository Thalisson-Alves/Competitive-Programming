#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

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
    auto dijkstra = [&]() {
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
    while (flow < flow_limit and dijkstra()) {
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

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n), b(n);
  for (auto &[x, y] : a) cin >> x >> y;
  for (auto &[x, y] : b) cin >> x >> y;
  MinCostFlow<int, ll> mcf(2*n+2);
  int s = 2*n, t = s+1;
  for (int i = 0; i < n; i++) {
    mcf.add_edge(s, i, 1, 0);
    mcf.add_edge(i+n, t, 1, 0);
    for (int j = 0; j < n; j++)
      mcf.add_edge(i, j+n, 1, (ll)(hypotl(a[i].first-b[j].first,a[i].second-b[j].second)*1.5e12+.5));
  }
  auto [flow, cost] = mcf.flow(s, t);
  if (flow != n) {
    cout << "-1\n";
    return;
  }
  vector<int> res(n);
  for (const auto &p : mcf.paths(s, t)) res[p[1]] = p[2]-n;
  for (int i = 0; i < n; i++) cout << res[i]+1 << " \n"[i==n-1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
