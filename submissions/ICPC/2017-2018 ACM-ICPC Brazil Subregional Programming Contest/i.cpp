#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> coins(n);
  for (auto &x : coins) cin >> x;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  ll res = 0;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    for (auto [v, w] : g[u]) if (v != p) {
      self(self, v, u);
      res += (coins[v] + k - 1ll) / k * w;
      coins[u] += coins[v];
    }
  };
  dfs(dfs, 0, -1);
  cout << 2 * res << '\n';
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
