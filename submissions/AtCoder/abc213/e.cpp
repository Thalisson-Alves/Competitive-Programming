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

  auto in_range = [&](int x, int y) { return 0 <= x and x < n and 0 <= y and y < m; };
  constexpr int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  dist[0][0] = 0;
  deque<pair<int, int>> dq({{0, 0}});
  while (!dq.empty()) {
    auto [cx, cy] = dq.front(); dq.pop_front();
    if (cx == n-1 and cy == m-1) break;

    for (auto [dx, dy] : dir) {
      auto x = cx + dx;
      auto y = cy + dy;
      if (!in_range(x, y)) continue;
      auto cost = dist[cx][cy] + (g[x][y] == '#');
      if (dist[x][y] < cost) continue;
      if (g[x][y] == '.') {
        if (dist[x][y] > cost) {
          dist[x][y] = cost;
          dq.emplace_front(x, y);
        }
        continue;
      }

      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          if (in_range(x + i, y + j) and dist[x + i][y + j] > cost) {
            dist[x + i][y + j] = cost;
            dq.emplace_back(x + i, y + j);
          }
        }
      }
    }
  }

  cout << dist[n-1][m-1] << '\n';
}

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
