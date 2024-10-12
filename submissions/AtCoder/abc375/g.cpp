#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  vector<tuple<int, int, ll>> es(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    es[i] = {u, v, w};
  }
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
  auto [d1, w1] = dijkstra(0);
  auto [d2, w2] = dijkstra(n-1);
  for (auto [u, v, w] : es) {
    bool res = 0;
    res |= (d1[u]!=LLONG_MAX and d2[v]!=LLONG_MAX and d1[u]+w+d2[v] == d1[n-1] and make_pair(w1[u].first*w2[v].first%m1,w1[u].second*w2[v].second%m2) == w1[n-1]);
    res |= (d1[v]!=LLONG_MAX and d2[u]!=LLONG_MAX and d1[v]+w+d2[u] == d1[n-1] and make_pair(w1[v].first*w2[u].first%m1,w1[v].second*w2[u].second%m2) == w1[n-1]);
    cout << (res ? "Yes" : "No") << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
