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

void dfs(const vector<vector<int>> &g, int u, int c, vector<int> &cs, int &ans)
{
  ans += cs[u] != c;
  for (auto x : g[u])
    dfs(g, x, cs[u], cs, ans);
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++)
  {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
  vector<int> cs(n);
  for (auto &x : cs) cin >> x;

  int ans = 0;
  dfs(g, 0, -1, cs, ans);
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

