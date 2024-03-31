#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, p, t;
  cin >> n >> m >> p >> t;
  --p, --t;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  vector<bool> ok(n);
  auto dist = [&]() {
    vector<ll> d(g.size(), numeric_limits<ll>::max());
    d[p] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, p);
    while (not pq.empty()) {
      auto [cost, u] = pq.top(); pq.pop();
      if (cost != d[u]) continue;
      if (u == t) ok[u] = 1;

      for (auto [v, w] : g[u]) {
        auto new_dist = d[u] + w;
        if (d[v] == new_dist) {
          ok[v] = ok[v] and ok[u];
        } else if (d[v] > new_dist) {
          d[v] = new_dist;
          ok[v] = ok[u];
          pq.emplace(new_dist, v);
        }
      }
    }
    return d;
  }();

  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (dist[i] == 2 * dist[t] and ok[i])
      res.push_back(i);
  }

  if (res.empty()) {
    cout << "*\n";
  } else {
    for (auto x : res)
      cout << x + 1 << ' ';
    cout << '\n';
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
