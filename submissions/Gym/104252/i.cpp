#include <bits/stdc++.h>
#include <memory>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(const vector<vector<int>> &g, pair<int, int> start, set<pair<int, int>> &vis)
{
  using T = pair<int, int>;
  priority_queue<T, vector<T>, greater<T>> pq;
  pq.push(start);
  vis.insert(start);

  vector<int> this_vis(g.size()*g[0].size()+1);
  auto ans = 0;
  while (not pq.empty())
  {
    auto cur = pq.top(); pq.pop();
    for (auto [x, y] : dir4)
    {
      x += cur.first;
      y += cur.second;

      if (x < 0 or y < 0 or x >= (int)g.size() or y >= (int)g[0].size() or this_vis[g[x][y]] or g[x][y] <= g[cur.first][cur.second])
        continue;

      pq.emplace(x, y);
      vis.emplace(x, y);
      this_vis[g[x][y]] = true;;
    }
    ans++;
  }

  return ans;
}

void solve()
{
  int r, c;
  cin >> r >> c;
  vector<vector<int>> v(r, vector<int>(c));
  for (auto &row : v) for (auto &x : row) cin >> x;

  set<pair<int, int>> vis;
  auto ans = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (not vis.count({i, j}))
        ans = max(ans, bfs(v, {i, j}, vis));
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

