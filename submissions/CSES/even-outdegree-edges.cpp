#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<int>> ng(n);
  vector<int> tin(n, -1);
  int t = 0;
  auto dfs = [&](auto &&self, int u) -> void {
    tin[u] = t++;
    for (auto v : g[u]) {
      if (tin[v] == -1) self(self, v);
      if (tin[v] < tin[u]) continue;
      if (size(ng[v])&1) ng[v].push_back(u);
      else ng[u].push_back(v);
    }
  };
  for (int i = 0; i < n; i++) {
    if (tin[i] == -1) dfs(dfs, i);
    if (size(ng[i]) & 1) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  for (int u = 0; u < n; u++) {
    for (auto v : ng[u]) {
      cout << u+1 << ' ' << v+1 << '\n';
    }
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
