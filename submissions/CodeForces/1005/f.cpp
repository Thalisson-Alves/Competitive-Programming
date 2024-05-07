#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);
  map<pair<int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    mp[minmax(u, v)] = i;
  }

  vector<vector<pair<int, int>>> eq(n);
  queue<pair<int, int>> q({{0, -1}});
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  while (!q.empty()) {
    auto [u, p] = q.front();
    q.pop();

    for (auto v : g[u]) {
      if (dist[u] + 1 < dist[v]) {
        q.emplace(v, u);
        dist[v] = dist[u] + 1;
      }
      if (dist[u] + 1 == dist[v])
        eq[v].push_back(minmax(u, v));
    }
  }

  vector<string> res;
  string cur(m, '0');
  auto dfs = [&](auto &&self, int i) -> void {
    if ((int)res.size() >= k) return;
    if (i >= n) {
      res.push_back(cur);
      return;
    }

    for (auto p : eq[i]) {
      cur[mp[p]] = '1';
      self(self, i+1);
      cur[mp[p]] = '0';
    }
  };
  dfs(dfs, 1);

  cout << res.size() << '\n';
  for (const auto &x : res) cout << x << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
