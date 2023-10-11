#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

bool dfs(const vector<vector<int>> &g, int s, vector<short> &vis, short team)
{
  if (vis[s] and vis[s] != team) return false;
  vis[s] = team;
  bool ans = true;
  team = (team % 2) + 1;
  for (auto x : g[s])
  {
    if (vis[x] == team) continue;
    if (vis[x] and vis[x] != team) return false;
    vis[x] = team;

    ans &= dfs(g, x, vis, team);
  }

  return ans;
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
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<short> ans(n);
  bool possible = true;
  for (int i = 0; possible and i < n; i++)
  {
    if (not ans[i])
      possible &= dfs(g, i, ans, 1);
    assert(ans[i]);
  }

  if (not possible)
    cout << "IMPOSSIBLE\n";
  else
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
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

