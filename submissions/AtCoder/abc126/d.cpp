#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void dfs(const vector<vector<pair<int, int>>> &g, int u, int p, vector<int> &ans, int cur_color) {
  ans[u] = cur_color;
  for (auto [v, w] : g[u]) if (p != v) {
    dfs(g, v, u, ans, (w ? 1 - cur_color : cur_color));
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n-1; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    w &= 1;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  vector<int> ans(n);
  dfs(g, 0, -1, ans, 0);
  for (auto x : ans) cout << x << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
 
  return 0;
}
