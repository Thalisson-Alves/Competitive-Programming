#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'L')
        q.emplace(i, j);
    }
  }
  constexpr int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  while (q.size()) {
    auto [cx, cy] = q.front();
    q.pop();
    vector<pair<int, int>> nei;
    for (auto [dx, dy] : dir) {
      int x = dx + cx;
      int y = dy + cy;
      if (x < 0 or x >= n or y < 0 or y >= m or g[x][y] != '.') continue;
      nei.emplace_back(x, y);
    }
    if (g[cx][cy] == 'L') {
      for (auto x : nei) q.push(x);
    } else if (nei.size() <= 1) {
      if (nei.size()) q.push(nei.back());
      g[cx][cy] = '+';
    }
  }
  for (auto &x : g) cout << x << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}
