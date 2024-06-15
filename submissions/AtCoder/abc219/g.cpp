#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (auto &v : g) {
    sort(v.begin(), v.end(), [&](int a, int b) { return g[a].size() > g[b].size(); });
  }

  constexpr auto MAX = 500u;

  vector<pair<int, int>> res(n), lazy(n, {INT_MAX, INT_MAX});
  for (int i = 0; i < n; i++)
    res[i] = {INT_MAX, i + 1};

  auto update_value = [&](int u) {
    for (auto v : g[u]) {
      if (g[v].size() < MAX) break;
      if (lazy[v] < res[u])
        res[u] = lazy[v];
    }
  };

  while (q--) {
    int u; cin >> u; --u;

    update_value(u);

    if (g[u].size() < MAX) {
      for (auto v : g[u])
        res[v] = {q, res[u].second};
    } else {
      lazy[u] = {q, res[u].second};
    }
  }

  for (int i = 0; i < n; i++) {
    update_value(i);
    cout << res[i].second << " \n"[i == n-1];
  }
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
