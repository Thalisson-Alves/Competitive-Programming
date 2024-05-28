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
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }

  vector<int> dp(n);
  auto dfs = [&](auto &&self, int u) -> int {
    auto &res = dp[u];
    if (res) return res;
    for (auto v : g[u])
      res = max(res, self(self, v) + 1);
    return res;
  };
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, dfs(dfs, i));
  }
  cout << res << '\n';
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
