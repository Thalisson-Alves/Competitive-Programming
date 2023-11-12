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

ll bfs(const vector<string> &g, pair<int, int> s, pair<int, int> t, int k) {
  vector<vector<ll>> dist(g.size(), vector<ll>(g[0].size(), LLONG_MAX));
  dist[s.first][s.second] = 0;

  queue<pair<int, int>> q;
  q.push(s);

  vector<vector<pair<bool, bool>>> vis(g.size(), vector<pair<bool,bool>>(g[0].size()));

  while (not q.empty()) {
    auto [cx, cy] = q.front(); q.pop();

    const pair<bool, bool> tp = {1, 1};
    auto new_dist = dist[cx][cy] + 1;
    for (auto [dx, dy] : dir4) {
      if (dx and vis[cx][cy].first) continue;
      if (dy and vis[cx][cy].second) continue;

      for (int d = 1; d <= k; d++) {
        int x = cx + dx * d;
        int y = cy + dy * d;

        if (x < 0 or x >= (int)g.size() or y < 0 or y >= (int)g[0].size() or g[x][y] == '#' or vis[x][y] == tp) break;

        if (new_dist < dist[x][y]) {
          dist[x][y] = new_dist;
          if (q.emplace(x, y) == t) return new_dist;

          if (d != k) {
            if (dx) vis[x][y].first = 1;
            if (dy) vis[x][y].second = 1;
          }
        }
      }
    }
  }

  return dist[t.first][t.second];
}

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> g(n);
  for (auto &s : g) cin >> s;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  --a, --b, --c, --d;

  auto res = bfs(g, {a, b}, {c, d}, k);
  cout << (res == LLONG_MAX ? -1 : res) << '\n';
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
