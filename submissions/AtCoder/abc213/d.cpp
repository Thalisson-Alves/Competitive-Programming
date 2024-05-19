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
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (auto &row : g) sort(row.begin(), row.end());
  vector<int> res;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    res.push_back(u + 1);
    for (auto v : g[u]) if (v != p) {
      self(self, v, u);
      res.push_back(u + 1);
    }
  };
  dfs(dfs, 0, -1);
  for (auto x : res) cout << x << ' ';
  cout << '\n';
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
