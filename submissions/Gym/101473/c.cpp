#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

int dfs(const vector<set<int>> &g, int u, const vector<int> &ages, const vector<int> &mp, vector<int> &dp)
{
  int ans = INT_MAX;
  dbg(u);
  for (auto x : g[u])
  {
    ans = min(ans, ages[mp[x]]);
    if (!dp[x])
      dfs(g, x, ages, mp, dp);
    ans = min(ans, dp[x]);
  }
  dbg(u, ans);
  return dp[u] = ans;
}

void solve()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> ages(n);
  for (auto &x : ages) cin >> x;
  vector<set<int>> g(n);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[y].insert(x);
  }

  vector<int> mp(n);
  iota(all(mp), 0);

  while (q--)
  {
    char t;
    cin >> t;
    if (t == 'P')
    {
      int x;
      cin >> x;
      --x;

      dbg(x);
      dbg(mp);

      vector<int> vis(n);
      auto cur = find(all(mp), x) - mp.begin();
      auto ans = dfs(g, cur, ages, mp, vis);
      if (ans == INT_MAX)
        cout << "*\n";
      else
        cout << ans << '\n';
    }
    else
    {
      int x, y;
      cin >> x >> y;
      --x, --y;
      auto cx = find(all(mp), x) - mp.begin();
      auto cy = find(all(mp), y) - mp.begin();
      swap(mp[cx], mp[cy]);
    }
  }
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
