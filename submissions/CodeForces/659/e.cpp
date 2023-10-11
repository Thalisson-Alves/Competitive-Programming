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

struct UFDS
{
  vector<int> ps, sz;
  int components;

  UFDS(int n) : ps(n), sz(n, 1), components(n)
  {
    iota(all(ps), 0);
  }

  int find_set(int x)
  {
    return (x == ps[x] ? x : (ps[x] = find_set(ps[x])));
  }

  bool same_set(int x, int y)
  {
    return find_set(x) == find_set(y);
  }

  void union_set(int x, int y)
  {
    x = find_set(x);
    y = find_set(y);
    
    if (x == y) return;

    if (sz[x] < sz[y])
      swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    components--;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;
  UFDS ufds(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ufds.union_set(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> edges(n);
  for (int i = 0; i < n; i++) {
    edges[ufds.find_set(i)] += (int)g[i].size();
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto p = ufds.find_set(i);
    if (i != p) continue;
    dbg(i, ufds.sz[p], edges[p]);
    ans += ufds.sz[p] - 1 == edges[p] / 2;
  }
  cout << ans << "\n";
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
