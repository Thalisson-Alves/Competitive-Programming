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
  vector<string> g(n);
  for (auto &x : g) cin >> x;

  const vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> vis(n, vector<int>(m));
  int id = 1;
  auto dfs = [&](auto &&self, int cx, int cy) -> int {
    vis[cx][cy] = id;
    for (auto [dx, dy] : dir) {
      auto x = dx + cx;
      auto y = dy + cy;
      if (x >= 0 and x < n and y >= 0 and y < m and g[x][y] == '#')
        return 1;
    }
    int res = 1;
    for (auto [dx, dy] : dir) {
      auto x = dx + cx;
      auto y = dy + cy;
      if (x >= 0 and x < n and y >= 0 and y < m) {
        if (!vis[x][y]) res += self(self, x, y);
        else if (vis[x][y] < id) res++, vis[x][y] = id;
      }
    }
    return res;
  };
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '.' and !vis[i][j]) {
        res = max(res, dfs(dfs, i, j));
        ++id;
      }
    }
  }
  cout << res << '\n';
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
