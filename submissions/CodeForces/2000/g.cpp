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
  int t[3];
  for (auto &x : t) cin >> x;
  vector<vector<tuple<int, ll, ll>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    --u, --v;
    g[u].emplace_back(v, a, b);
    g[v].emplace_back(u, a, b);
  }

  auto f = [&](int s) {
    vector<ll> dist(g.size(), LLONG_MAX);
    dist[0] = s;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(dist[0], 0);
    while (not pq.empty()) {
      auto [cost, u] = pq.top(); pq.pop();
      if (cost != dist[u]) continue;
      if (cost > t[0]) break;

      for (auto [v, w1, w2] : g[u]) {
        if (cost + w1 <= t[1] or cost >= t[2]) {
          if (dist[v] > dist[u] + w1) {
            dist[v] = dist[u] + w1;
            pq.emplace(dist[v], v);
          }
        } else {
          if (dist[v] > t[2] + w1) {
            dist[v] = t[2] + w1;
            pq.emplace(dist[v], v);
          }
        }
        if (dist[v] > dist[u] + w2) {
          dist[v] = dist[u] + w2;
          pq.emplace(dist[v], v);
        }
      }
    }
    return dist[n-1] <= t[0];
  };

  int l = 0, r = t[0];
  while (l <= r) {
    auto mid = midpoint(l, r);
    if (f(mid)) l = mid + 1;
    else r = mid - 1;
  }
  cout << r << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
