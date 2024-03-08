#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (auto &row : mat) for (auto &x : row) cin >> x;
  queue<pair<int, int>> q({{0, 0}});
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  dist[0][0] = 0;
  int res = INT_MAX;
  while (not q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (y == m-1) {
      auto dif = abs((n-1+dist[x][y])%n - x);
      res = min(res, dist[x][y] + min(dif, n - dif));
    }

    { // DOWN
      auto nx = (x+2)%n;
      if (!mat[(x+1)%n][y] and !mat[nx][y] and dist[nx][y] > dist[x][y]+1) {
        q.emplace(nx, y);
        dist[nx][y] = dist[x][y] + 1;
      }
    }

    { // RIGHT
      auto nx = (x+1)%n;
      auto ny = y+1;
      if (ny < m and !mat[nx][ny] and dist[nx][ny] > dist[x][y]+1) {
        dist[nx][ny] = dist[x][y] + 1;
        q.emplace(nx, ny);
      }
    }
  }
  cout << (res == INT_MAX ? -1 : res) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
