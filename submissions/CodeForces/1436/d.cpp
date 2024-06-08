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
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    g[i].push_back(--x);
    g[x].push_back(i);
  }
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  // max, sum, cnt_leafs
  vector<array<ll, 3>> dp(n, {0});
  auto dfs = [&](auto &&self, int u, int p) -> void {
    if (u and g[u].size() == 1) {
      dp[u] = {a[u], a[u], 1};
      return;
    }

    auto &res = dp[u];
    for (auto v : g[u]) if (v != p) {
      self(self, v, u);
      res[0] = max(res[0], dp[v][0]);
      res[1] += dp[v][1];
      res[2] += dp[v][2];
    }

    res[1] += a[u];
    res[0] = max(res[0], (res[1] + res[2] - 1) / res[2]);
  };

  dfs(dfs, 0, -1);
  cout << dp[0][0] << '\n';
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
