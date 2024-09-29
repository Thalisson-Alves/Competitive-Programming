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
  vector<vector<array<ll, 3>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back() = {u, v, w};
    g[v].emplace_back() = {u, v, w};
  }
  vector<ll> res(n, LLONG_MAX);
  auto dfs = [&](auto &&self, int u) -> void {
    for (auto e : g[u]) {
      auto v = u ^ e[0] ^ e[1];
      if (res[v] != LLONG_MAX) continue;
      ll nv;
      if (v == e[1]) nv = e[2] + res[u];
      else nv = res[u] - e[2];
      res[v] = nv;
      self(self, v);
    }
  };
  for (int i = 0; i < n; i++) if (res[i] == LLONG_MAX) {
    res[i] = 0;
    dfs(dfs, i);
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " \n"[i==n-1];
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
