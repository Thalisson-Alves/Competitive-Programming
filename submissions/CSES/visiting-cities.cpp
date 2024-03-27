#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

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

    for (auto [v, w] : g[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        pq.emplace(dist[u] + w, v);
      }
    }
  }

  return make_pair(dist, prev);
}

template <typename Undigraph> void find_articulations(const Undigraph &g, auto &&f) {
  static_assert(std::is_invocable_r_v<void, decltype(f), int>);

  vector<int> tin(g.size()), tout(g.size()), low(g.size());
  int timer = 1;

  auto dfs = [&](auto &&self, int u, int p) -> void {
    tin[u] = low[u] = timer++;
    int cnt = 0;

    for (auto v : g[u]) if (v != p) {
      if (tin[v]) {
        low[u] = min(low[u], tin[v]);
      } else {
        self(self, v, u);
        low[u] = min(low[u], low[v]);
        ++cnt;
        if (~p and low[v] >= tin[u]) {
          f(u);
        }
      }
    }

    if (p == -1 and cnt > 1) f(u);
  };

  for (int i = 0; i < (int)g.size(); i++) {
    if (!tin[i])
      dfs(dfs, i, -1);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n), gr(n);
  vector<tuple<int, int, ll>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    gr[v].emplace_back(u, w);
    edges[i] = {u, v, w};
  }

  auto [d1, _] = dijkstra(g, 0);
  auto [d2, __] = dijkstra(gr, n - 1);

  vector<vector<int>> rg(n);
  for (auto [u, v, w] : edges) {
    if (d1[u] + d2[v] + w == d1[n-1]) {
      rg[u].push_back(v);
      rg[v].push_back(u);
    }
  }

  vector<bool> art(n);
  art[0] = art[n-1] = 1;
  find_articulations(rg, [&](auto u) {
    art[u] = 1;
  });

  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (art[i])
      res.push_back(i);
  }
  cout << res.size() << '\n';
  for (int i = 0; i < (int)res.size(); i++)
    cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
