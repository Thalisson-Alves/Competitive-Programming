#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n), ng(n);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    --u, --v;
    auto &x = (t ? g : ng);
    x[u].emplace_back(v, i);
    x[v].emplace_back(u, i);
    edges[i] = {u, v};
  }
  vector<int> sz(n, -1);
  auto dfs = [&](auto &&self, int u) -> void {
    sz[u] = (int)g[u].size()&1;
    for (auto [v, e] : ng[u]) if (sz[v] == -1) {
      self(self, v);
      sz[u] ^= sz[v];
      if (sz[v]) g[u].emplace_back(v, e), g[v].emplace_back(u, e);
    }
    ng[u].clear();
  };
  vector<int> res(m);
  for (int u = 0; u < n; u++) {
    if (sz[u] == -1) dfs(dfs, u);
    if (g[u].size()&1) {
      cout << "N\n";
      return;
    }
  }
  vector<bool> vis(m);
  auto euler_cycle = [&](auto &&self, int u) -> void {
    while (g[u].size()) {
      auto [v, e] = g[u].back();
      g[u].pop_back();
      if (!vis[e]) {
        vis[e] = 1;
        self(self, v);
        res[e] = 2 * (edges[e] == make_pair(u, v)) - 1;
      }
    }
  };
  for (int i = 0; i < n; i++) euler_cycle(euler_cycle, i);
  cout << "S\n";
  for (auto x : res) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
