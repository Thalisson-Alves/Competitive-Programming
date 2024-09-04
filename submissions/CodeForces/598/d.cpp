#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

struct UFDS {
  vector<int> ps, sz;
  int components;
  UFDS(int n = 0) : ps(n), sz(n, 1), components(n) {
    iota(ps.begin(), ps.end(), 0);
  }
  int find(int x) { return (x == ps[x] ? x : (ps[x] = find(ps[x]))); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --components;
    return true;
  }
  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++components;
    return id;
  };
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  static const vector<pair<int,int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  UFDS ufds(n*m);
  vector<int> value(n*m, -1);
  auto dfs = [&](auto &&self, int i, int j) {
    if (~value[i*m+j]) return;
    int res = 0;
    for (auto [dx, dy] : dir) {
      auto x = i+dx, y = dy+j;
      if (x < 0 or x >= n or y < 0 or y >= m) continue;
      if (v[x][y] == '*') res++;
      else if (ufds.join(i*m+j, x*m+y)) self(self, x, y);
    }
    value[i*m+j] = res;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.' and value[i*m+j] == -1)
        dfs(dfs, i, j);
    }
  }
  vector<int> dp(n*m);
  for (int i = 0; i < n*m; i++) dp[ufds.find(i)] += value[i];
  while (k--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    cout << dp[ufds.find(x*m+y)] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
