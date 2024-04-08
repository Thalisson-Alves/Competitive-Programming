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
  for (auto &s : g)
    cin >> s;
  int k;
  cin >> k;
  vector<vector<int>> med(n, vector<int>(m));
  for (int i = 0; i < k; i++) {
    int r, c, x;
    cin >> r >> c >> x;
    --r, --c;
    med[r][c] = max(med[r][c], x);
  }

  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  int tx = -1, ty = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'S')
        q.emplace(i, j);
      else if (g[i][j] == 'T')
        tx = i, ty = j;
    }
  }

  constexpr int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  while (not q.empty()) {
    auto [cx, cy] = q.front();
    q.pop();
    auto &e = dist[cx][cy];
    e = max(e, med[cx][cy]);
    if (!e) continue;

    for (auto [dx, dy] : dir) {
      auto x = dx + cx;
      auto y = dy + cy;
      if (0 <= x and x < n and 0 <= y and y < m and g[x][y] != '#' and dist[x][y] < e - 1) {
        dist[x][y] = e - 1;
        q.emplace(x, y);
      }
    }
  }

  cout << (dist[tx][ty] >= 0 ? "Yes" : "No") << '\n';
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
