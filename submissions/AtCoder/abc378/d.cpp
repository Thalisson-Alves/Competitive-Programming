#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  int res = 0;
  constexpr pair<int, int> dir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<bool>> vis(n, vector<bool>(m));
  auto dfs = [&](auto &&self, int i, int j, int d) -> void {
    if (d == k) {
      ++res;
      return;
    }
    vis[i][j] = 1;
    for (auto [dx, dy] : dir) {
      int x = i + dx;
      int y = j + dy;
      if (0 <= x and x < n and 0 <= y and y < m and g[x][y] != '#' and !vis[x][y]) {
        self(self, x, y, d+1);
      }
    }
    vis[i][j] = 0;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '.') dfs(dfs, i, j, 0);
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
