#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

void dfs(const vector<vector<int>> &g, int cur, const int k, set<int> &vis)
{
  vis.insert(cur);
  for (auto x : g[cur])
    if (not vis.count(x) and (int) vis.size() < k)
      dfs(g, x, k, vis);
}

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for (auto &x : v) cin >> x;

  vector<vector<int>> g(n*m);
  auto cur_pos = 0, empty_cells = 0;
  for (auto i = 0; i < n; i++)
  {
    for (auto j = 0; j < m; j++)
    {
      if (v[i][j] == '#') continue;

      cur_pos = i*m+j;
      empty_cells++;
      for (auto [x, y] : dir)
      {
        x += i;
        y += j;
        if (0 <= x && x < n && 0 <= y && y < m && v[x][y] == '.')
          g[cur_pos].push_back(x*m+y);
      }
    }
  }

  set<int> vis;
  dfs(g, cur_pos, empty_cells - k, vis);
  for (auto i = 0; i < n; i++)
    for (auto j = 0; j < m; j++)
      if (v[i][j] == '.' and not vis.count(i*m+j))
        v[i][j] = 'X';

  for (const auto &x : v)
    cout << x << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();

  return 0;
}

