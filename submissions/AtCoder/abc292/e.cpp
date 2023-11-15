#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

set<int> bfs(const vector<vector<int>> &g, int s)
{
  queue<int> q;
  q.push(s);

  set<int> vis;
  vis.insert(s);

  while (not q.empty())
  {
    auto cur = q.front(); q.pop();

    for (auto x : g[cur])
    {
      if (vis.count(x)) continue;

      vis.insert(x);
      q.push(x);
    }
  }

  return vis;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;

    g[a].push_back(b);
  }

  ull ans = 0;
  for (int i = 0; i < n; i++)
  {
    auto vis = bfs(g, i);
    ans += vis.size() - g[i].size() - 1ull;
  }
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

