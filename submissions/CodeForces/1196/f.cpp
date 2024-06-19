#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<ll, int, int>> es(m);
  for (auto &[w, u, v] : es) cin >> u >> v >> w, --u, --v;
  sort(es.begin(), es.end());
  es.erase(es.begin() + min(k, m), es.end());
  vector<vector<pair<int, ll>>> g(n);
  for (auto [w, u, v] : es) {
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  using T = tuple<ll, int, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  map<pair<int, int>, ll> dist;
  for (int i = 0; i < n; i++) {
    pq.emplace(0, i, i);
    dist[{i, i}] = 0;
  }
  while (not pq.empty()) {
    auto [cost, u, s] = pq.top(); pq.pop();
    if (cost != dist[{u, s}]) continue;
    if (u != s and u <= s and !--k) {
      cout << cost << '\n';
      return;
    }

    for (auto [v, w] : g[u]) {
      if (!dist.count({v, s}) or dist[{v, s}] > cost + w) {
        dist[{v, s}] = cost + w;
        pq.emplace(cost + w, v, s);
      }
    }
  }
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
