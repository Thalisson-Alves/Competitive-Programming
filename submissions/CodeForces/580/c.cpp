#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define NDEBUG
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void dfs(const vector<vector<int>> &g, int u, int p, int c, int m, vector<int> &cs, int &ans)
{
  if (cs[u]) c++;
  else c = 0;

  if (c > m)
    return;

  if (g[u].size() == 1 and u != 0)
    ans++;

  for (auto x : g[u])
    if (x != p)
      dfs(g, x, u, c, m, cs, ans);
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> cs(n);
  for (int i = 0; i < n; i++)
    cin >> cs[i];

  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 0;
  dfs(g, 0, -1, 0, m, cs, ans);
  cout << ans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

