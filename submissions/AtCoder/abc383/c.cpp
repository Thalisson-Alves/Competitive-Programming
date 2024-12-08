#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'H') {
        q.emplace(i, j);
        dist[i][j] = 0;
      }
    }
  }
  constexpr int dir4[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  while (not q.empty()) {
    auto [ci, cj] = q.front();
    q.pop();
    if (dist[ci][cj] == d) break;
    for (auto [dx, dy] : dir4) {
      int i = dx + ci;
      int j = dy + cj;
      if (0 <= i and i < n and 0 <= j and j < m and g[i][j] != '#' and dist[i][j] > dist[ci][cj] + 1) {
        q.emplace(i, j);
        dist[i][j] = dist[ci][cj] + 1;
      }
    }
  }
  int res = 0;
  for (int i =0 ; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res += dist[i][j] != INT_MAX;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
