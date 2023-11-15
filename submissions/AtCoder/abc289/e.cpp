#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define debug(...) 42
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

ll bfs(const vector<vector<int>> &g, const vector<int> &v)
{
  set<pair<int, int>> vis;
  vis.emplace(0, g.size()-1);
  queue<tuple<int, int, ll>> q;
  q.emplace(0, g.size()-1, 0);
  while (not q.empty())
  {
    auto [a, b, cost] = q.front(); q.pop();
    if (a == (int)g.size()-1 and b == 0)
      return cost;

    for (auto x : g[a])
    {
      for (auto y : g[b])
      {
        if (vis.count({x, y}) or v[x] == v[y]) continue;
        q.emplace(x, y, cost+1);
        vis.emplace(x, y);
      }
    }
  }

  return -1;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++)
  {
    int x, y; cin >> x >> y;
    --x;--y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cout << bfs(g, v) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

