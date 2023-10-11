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

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
 
void dfs1(const vector<vector<int>> &g, vector<int> &order, vector<int> &vis, int s)
{
  vis[s] = true;
  for (auto x : g[s])
    if (not vis[x])
      dfs1(g, order, vis, x);

  order.push_back(s);
}
 
void dfs2(const vector<vector<int>> &g, vector<int> &teams, int s, int team)
{
  teams[s] = team;
  for (auto x : g[s])
    if (not teams[x])
      dfs2(g, teams, x, team);
}
 
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), gr(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }
 
  vector<int> order, vis(n);
  for (int i = 0; i < n; i++)
    if (not vis[i])
      dfs1(g, order, vis, i);
 
  reverse(all(order));
 
  dbg(order);
 
  vector<int> teams(n);
  int team = 0;
  for (auto i : order)
    if (not teams[i])
      dfs2(gr, teams, i, ++team);
 
  cout << team << '\n';
  for (int i = 0; i < n; i++)
    cout << teams[i] << " \n"[i == n - 1];
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

