#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;
  vector<vector<tuple<int, ll, ll>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, time, k;
    cin >> u >> v >> time >> k;
    --u, --v;
    g[u].emplace_back(v, time, k);
    g[v].emplace_back(u, time, k);
  }

  auto res = [&]() {
    vector<ll> dist(g.size(), numeric_limits<ll>::max());
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, s);
    while (not pq.empty()) {
      auto [cost, u] = pq.top(); pq.pop();
      if (cost != dist[u]) continue;

      for (auto [v, w, k] : g[u]) {
        auto out = (k - (cost % k)) % k;
        auto new_dist = cost + w + out;
        if (dist[v] > new_dist) {
          dist[v] = new_dist;
          pq.emplace(new_dist, v);
        }
      }
    }

    return dist[t];
  }();

  cout << (res == LLONG_MAX ? -1 : res) << '\n';
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
