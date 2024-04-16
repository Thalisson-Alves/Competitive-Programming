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

  vector<vector<pair<int, int>>> tp_pos(26);
  int si, sj, ti, tj;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ('a' <= g[i][j] and g[i][j] <= 'z')
        tp_pos[g[i][j] - 'a'].emplace_back(i, j);
      else if (g[i][j] == 'S')
        si = i, sj = j;
      else if (g[i][j] == 'G')
        ti = i, tj = j;
    }
  }
  auto res = [&]() -> int {
    static constexpr int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    queue<pair<int, int>> q({{si, sj}});
    vector<vector<uint>> dist(n, vector<uint>(m, UINT_MAX));
    dist[si][sj] = 0;

    while (!q.empty()) {
      auto [cx, cy] = q.front();
      q.pop();

      for (auto [dx, dy] : dir) {
        auto x = dx + cx;
        auto y = dy + cy;

        if (x < 0 or x >= n or y < 0 or y >= m or g[x][y] == '#') continue;

        if (dist[x][y] > dist[cx][cy] + 1) {
          dist[x][y] = dist[cx][cy] + 1;
          q.emplace(x, y);
        }
      }

      if ('a' <= g[cx][cy] and g[cx][cy] <= 'z') {
        for (auto [x, y] : tp_pos[g[cx][cy] - 'a']) {
          if (dist[cx][cy] + 1 < dist[x][y]) {
            dist[x][y] = dist[cx][cy] + 1;
            q.emplace(x, y);
          }
        }
        tp_pos[g[cx][cy] - 'a'].clear();
      }
    }

    return (int)dist[ti][tj];
  }();

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
