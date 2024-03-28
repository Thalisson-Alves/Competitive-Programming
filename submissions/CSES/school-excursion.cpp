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
    g[v].push_back(u);
  }

  vector<bool> vis(n);
  auto dfs = [&](auto &&self, int u) -> int {
    vis[u] = 1;
    int cnt = 1;
    for (auto v : g[u]) if (!vis[v]) {
      cnt += self(self, v);
    }
    return cnt;
  };

  bitset<100001> mask;
  mask[0] = 1;
  for (int i = 0; i < n; i++) if (!vis[i]) {
    mask |= mask << dfs(dfs, i);
  }

  for (int i = 1; i <= n; i++) cout << mask[i];
  cout << '\n';
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
