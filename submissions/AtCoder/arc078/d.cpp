#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  auto dfs = [](auto &&self, const auto &g, int u, int p, auto &dist) -> void {
    for (auto x : g[u]) if (x != p) {
      dist[x] = dist[u] + 1;
      self(self, g, x, u, dist);
    }
  };

  vector<int> df(n), ds(n);
  dfs(dfs, g, 0, -1, df);
  dfs(dfs, g, n-1, -1, ds);

  int fennec = 0;
  for (int i = 0; i < n; i++) fennec += (df[i] <= ds[i]);
  dbg(fennec, n-fennec);

  cout << (2*fennec > n ? "Fennec" : "Snuke") << '\n';
}

int32_t main()
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
