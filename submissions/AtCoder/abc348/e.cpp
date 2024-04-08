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
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> cs(n);
  for (auto &x : cs) cin >> x;

  vector<ll> sum(n);
  vector<int> dist(n);
  {
    auto dfs = [&](auto &&self, int u, int p) -> void {
      sum[u] += cs[u];
      for (auto v : g[u]) if (v != p) {
        dist[v] = dist[u] + 1;
        self(self, v, u);
        sum[u] += sum[v];
      }
    };
    dfs(dfs, 0, -1);
  }

  ll res = 0;
  for (int i = 0; i < n; i++)
    res += 1ll * dist[i] * cs[i];

  auto dfs = [&](auto &&self, int u, int p, ll value) -> void {
    res = min(res, value);
    for (auto v : g[u]) if (v != p) {
      self(self, v, u, value - 2 * sum[v] + sum[0]);
    }
  };
  dfs(dfs, 0, -1, res);

  cout << res << '\n';
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
