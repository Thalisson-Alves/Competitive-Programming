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
ll oo = 1e18;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

int find_last(const vector<vector<int>> &g, int s)
{
  queue<int> q;
  q.push(s);

  vector<char> vis(g.size());
  vis[s] = true;

  int res = s;
  while (not q.empty())
  {
    auto cur = q.front();
    res = cur;
    q.pop();

    for (auto x : g[cur])
      if (not vis[x])
      {
        q.push(x);
        vis[x] = true;
      }
  }

  return res;
}

int bfs(const vector<vector<int>> &g, int s, int e)
{
  queue<pair<int, int>> q;
  q.emplace(s, 0);

  vector<char> vis(g.size());
  vis[s] = true;

  while (not q.empty())
  {
    auto [cur, cost] = q.front();
    if (cur == e)
      return cost;
    q.pop();

    for (auto x : g[cur])
      if (not vis[x])
      {
        q.emplace(x, cost+1);
        vis[x] = true;
      }
  }

  return -1;
}

void solve()
{
  int n1, n2, m;
  cin >> n1 >> n2 >> m;
  vector<vector<int>> g(n1+n2);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto l1 = find_last(g, 0);
  auto l2 = find_last(g, n1+n2-1);

  g[l1].push_back(l2);
  g[l2].push_back(l1);

  cout << bfs(g, 0, n1+n2-1) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

