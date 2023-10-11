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

  UFDS(int n) : ps(n+1), sz(n+1, 1), components(n)
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

#define TV(_i, _j, _m) (_i * _m + _j)

void dfs(vector<string> &g, int i, int j, UFDS &ufds) {
  for (auto [dx, dy] : dir4) {
    int x = dx + i;
    int y = dy + j;
    if (x >= 0 and x < (int)g.size() and y >= 0 and y < (int)g[0].size() and g[x][y] == '.') {
      ufds.union_set(TV(i,j,g[0].size()), TV(x,y,g[0].size()));
      g[x][y] = ',';
      dfs(g, x, y, ufds);
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (auto &x : v) cin >> x;

  UFDS ufds(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.') {
        v[i][j] = ',';
        dfs(v, i, j, ufds);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '*') {
        set<int> vis;
        ll sum = 1;
        for (auto [dx, dy] : dir4) {
          int x = dx + i;
          int y = dy + j;
          if (x >= 0 and x < n and y >= 0 and y < m and v[x][y] == ',' and not vis.count(ufds.find_set(TV(x,y,m)))) {
            auto p = ufds.find_set(TV(x,y,m));
            sum += ufds.sz[p];
            vis.insert(p);
          }
        }
        v[i][j] = '0' + (sum % 10);
      }
    }
  }

  for (auto &x : v) {
    for (auto &c : x) if (c == ',') c = '.';
    cout << x << '\n';
  }
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
