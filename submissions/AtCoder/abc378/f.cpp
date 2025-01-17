#include <bits/stdc++.h>
using namespace std;
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
  UFDS ufds(n);
  for (int i = 0; i < n; i++) {
    for (auto j : g[i]) {
      if (g[i].size() == 3 and g[j].size() == 3)
        ufds.join(i, j);
    }
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) if (g[i].size() == 3) {
    int p = ufds.find(i);
    for (auto j : g[i]) {
      if (g[j].size() == 2) cnt[p]++;
    }
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += cnt[i]*(cnt[i]-1ll)/2;
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
