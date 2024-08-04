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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<unordered_set<int>> g(n);
  int m;
  cin >> m;
  UFDS ufds(n);
  map<pair<int, int>, int> id;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (ufds.join(u, v)) {
      id[minmax(u, v)] = i+1;
      g[u].insert(v);
      g[v].insert(u);
    }
  }

  vector<int> res;
  auto dfs = [&](auto &&self, int u, int p, int s) -> void {
    for (auto v : g[u]) if (v != p) {
      self(self, v, u, s);
      if (a[v] == s) {
        res.push_back(id[minmax(u, v)]);
        swap(a[v], a[u]);
        return;
      }
    }
  };

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (g[i].size() == 1)
      q.push(i);
  }
  while (q.size()) {
    auto u = q.front();
    q.pop();

    if (a[u] != u+1)
      dfs(dfs, u, -1, u+1);

    if (a[u] != u+1) {
      cout << "-1\n";
      return;
    }

    for (auto v : g[u]) {
      g[v].erase(u);
      if (g[v].size() == 1)
        q.push(v);
    }
  }

  cout << res.size() << '\n';
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " \n"[i == (int)res.size()-1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
