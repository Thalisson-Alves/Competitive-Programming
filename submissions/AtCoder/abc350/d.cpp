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

  UFDS(int n) : ps(n), sz(n, 1), components(n) {
    iota(ps.begin(), ps.end(), 0);
  }

  int find(int x) { return (x == ps[x] ? x : (ps[x] = find(ps[x]))); }

  bool same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    if (sz[x] < sz[y])
      swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --components;
    return true;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  UFDS ufds(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ufds.join(u, v);
  }

  vector<set<pair<int, int>>> edges(n);
  for (int i = 0; i < n; i++) {
    for (auto x : g[i]) {
      edges[ufds.find(i)].insert(minmax(i, x));
    }
  }

  vector<int> cnt(n);
  ll res = 0;
  for (int i = 0; i < n; i++) if (i == ufds.find(i)) {
    res += 1ll * ufds.sz[i] * (ufds.sz[i] - 1) / 2 - (int)edges[i].size();
  }
  cout << res << '\n';
}

int32_t main() {
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
