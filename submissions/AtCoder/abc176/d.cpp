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
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1},  {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
  int n, m;
  cin >> n >> m;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  --a, --b, --c, --d;
  vector<string> g(n);
  for (auto &x : g) cin >> x;

  vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
  vis[a][b] = 0;

  using PQ = tuple<int, int, int>;
  priority_queue<PQ, vector<PQ>, greater<PQ>> pq;
  pq.emplace(0, a, b);

  while (not pq.empty()) {
    auto [cost, cx, cy] = pq.top();
    pq.pop();

    if (cost != vis[cx][cy]) continue;

    for (int dx = -2; dx <= 2; dx++) {
      for (int dy = -2; dy <= 2; dy++) {
        int new_cost = cost + (abs(dx) + abs(dy) > 1);
        int x = dx + cx;
        int y = dy + cy;
        if (0 <= x and x < n and 0 <= y and y < m and g[x][y] == '.' and new_cost < vis[x][y]) {
          vis[x][y] = new_cost;
          pq.emplace(new_cost, x, y);
        }
      }
    }
  }

  cout << (vis[c][d] == INT_MAX ? -1 : vis[c][d]) << '\n';
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
