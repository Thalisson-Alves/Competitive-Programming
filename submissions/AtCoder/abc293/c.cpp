#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

int dfs(const vector<vector<int>> &g, pair<int, int> s, set<int> &vis)
{
  int n = (int)g.size();
  int m = (int)g[0].size();
  auto [x, y] = s;

  if (x == n-1 and y == m-1)
    return 1;

  auto ans = 0;
  if (x < n-1 and not vis.count(g[x+1][y]))
  {
    vis.insert(g[x+1][y]);
    ans += dfs(g, {x+1, y}, vis);
    vis.erase(g[x+1][y]);
  }
  if (y < m-1 and not vis.count(g[x][y+1]))
  {
    vis.insert(g[x][y+1]);
    ans += dfs(g, {x, y+1}, vis);
    vis.erase(g[x][y+1]);
  }
  return ans;
}

void solve()
{
  int n, m;
  cin>> n>>m;
  vector<vector<int>> g(n, vector<int>(m));
  for(auto & row: g) for (auto &x: row) cin >> x;

  set<int> vis;
  vis.emplace(g[0][0]);
  cout << dfs(g, {0, 0}, vis) <<'\n';
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

