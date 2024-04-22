#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template <typename Graph> auto dijkstra(const Graph &g, int s) {
  vector<ll> dist(g.size(), numeric_limits<ll>::max());
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, s);
  while (not pq.empty()) {
    auto [cost, u] = pq.top(); pq.pop();
    if (cost > dist[u]) continue;

    for (auto [v, w] : g[u]) {
      if (dist[v] > cost + w) {
        dist[v] = cost + w;
        pq.emplace(cost + w, v);
      }
    }
  }

  return dist;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[--a].emplace_back(--b, c);
  }

  for (int i = 0; i < n; i++) {
    auto res = dijkstra(g, i)[i];
    cout << (res == LLONG_MAX ? -1 : res) << '\n';
  }
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
