#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

auto warnsdorff(int sx, int sy) {
  constexpr int dir[][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
  vector<vector<int>> g(8, vector<int>(8));
  auto for_each_neighbor = [&](int x, int y, auto f) {
    for (int k = 0; k < 8; k++) {
      auto nx = dir[k][0] + x;
      auto ny = dir[k][1] + y;

      if (0 <= nx and nx < 8 and 0 <= ny and ny < 8 and !g[nx][ny])
        f(nx, ny);
    }
  };
  auto degree = [&](int x, int y) {
    int cnt = 0;
    for_each_neighbor(x, y, [&](auto, auto) {
      ++cnt;
    });
    return cnt;
  };
  auto dfs = [&](auto &&self, int x, int y, int move) -> bool {
    g[x][y] = move;
    if (move == 8*8) return true;

    vector<tuple<int, int, int>> v;
    for_each_neighbor(x, y, [&](auto a, auto b) {
      v.emplace_back(degree(a, b), a, b);
    });

    sort(all(v));

    for (auto [_, a, b] : v) {
      if (self(self, a, b, move+1)) return true;
    }

    g[x][y] = 0;
    return false;
  };

  dfs(dfs, sx, sy, 1);
  return g;
}

void solve() {
  int x, y;
  cin >> x >> y;
  --x, --y;

  auto res = warnsdorff(y, x);
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      cout << res[i][j] << " \n"[j == 7];
}

int32_t main()
{
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
