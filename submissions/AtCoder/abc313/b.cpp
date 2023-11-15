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

void dfs(const vector<vector<int>> &g, int s, vector<char> &vis)
{
  vis[s] = true;
  for (auto v : g[s])
  {
    if (vis[v]) continue;
    dfs(g, v, vis);
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }

  for (int i = 0; i < n; i++)
  {
    vector<char> vis(n);
    dfs(g, i, vis);
    if (all_of(all(vis), [](char x){return x;}))
    {
      cout << i+1 << '\n';
      return;
    }
  }
  cout << "-1\n";
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
 
