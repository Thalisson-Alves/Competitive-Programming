#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dist(n);
  vector<ll> sum(n);
  {
    auto dfs = [&](auto &&self, int u, int p) -> void {
      sum[u] += a[u];
      for (auto v : g[u]) if (v != p) {
        dist[v] = dist[u] + 1;
        self(self, v, u);
        sum[u] += sum[v];
      }
    };
    dfs(dfs, 0, -1);
  };

  ll cost = 0;
  for (int i = 0; i < n; i++) {
    cost += 1ll * dist[i] * a[i];
  }

  ll res = 0;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    res = max(res, cost);
    for (auto v : g[u]) if (v != p) {
      auto dif = sum[0] - 2 * sum[v];
      cost += dif;
      self(self, v, u);
      cost -= dif;
    }
  };
  dfs(dfs, 0, -1);
  cout << res << '\n';
}

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
