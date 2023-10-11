#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void tree_size(const vector<vector<int>> &g, int u, int p, vector<int> &sz) {
  sz[u] = 1;
  for (auto x : g[u]) {
    if (x != p) {
      tree_size(g, x, u, sz);
      sz[u] += sz[x];
    }
  }
}

int tree_centroid(const vector<vector<int>> &g, int u, int p, const vector<int> &sz) {
  for (auto x : g[u]) {
    if (x != p) {
      if (sz[x] * 2 > (int)g.size()) return tree_centroid(g, x, u, sz);
    }
  }
  return u;
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> size(n);
  tree_size(g, 0, -1, size);
  cout << tree_centroid(g, 0, -1, size) + 1 << '\n';
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
