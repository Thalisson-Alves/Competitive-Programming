#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto &x : g) cin >> x;

  deque<pair<int,int>> q;
  q.emplace_back(0, 0);

  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  dist[0][0] = 0;

  while (not q.empty()) {
    auto [cx, cy] = q.front();
    if (cx == n-1 and cy == m-1) break;
    q.pop_front();

    for (auto [dx, dy] : dir4) {
      auto x = cx + dx;
      auto y = cy + dy;
      if (x < 0 or x >= n or y < 0 or y >= m) continue;

      auto new_cost = dist[cx][cy] + (g[cx][cy] != g[x][y]);
      if (dist[x][y] > new_cost) {
        dist[x][y] = new_cost;
        if (g[cx][cy] == g[x][y])
          q.emplace_front(x, y);
        else
          q.emplace_back(x, y);
      }
    }
  }

  cout << dist[n-1][m-1] << '\n';
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
