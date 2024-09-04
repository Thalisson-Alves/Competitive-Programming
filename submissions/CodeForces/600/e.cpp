#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void small_to_large(const vector<vector<int>> &g, auto &&add, auto &&rem, auto &&ans, int root=0) {
  vector<int> sz(size(g)), pre(size(g)), path(size(g)), pos(size(g));
  int timer = -1;
  auto tour = [&](auto &&self, int u, int p) -> void {
    pre[u] = ++timer;
    path[pre[u]] = u;
    for (auto v : g[u]) if (v != p) self(self, v, u);
    pos[u] = timer;
    sz[u] = pos[u] - pre[u] + 1;
  };
  tour(tour, root, -1);
  auto dfs = [&](auto &&self, int u, int p = -1, bool keep=true) -> void {
    int mx = -1;
    for (auto v : g[u]) {
      if (v != p and (mx == -1 or sz[mx] < sz[v]))
        mx = v;
    }
    for (auto v : g[u]) if (v != p and v != mx) self(self, v, u, false);
    if (mx != -1) self(self, mx, u, true);
    add(u);
    for (auto v : g[u]) if (v != p and v != mx) {
      for (int i = pre[v]; i <= pos[v]; i++)
        add(path[i]);
    }
    ans(u);
    if (!keep) for (int i = pre[u]; i <= pos[u]; i++) rem(path[i]);
  };
  dfs(dfs, root);
}

void solve() {
  int n; cin >> n;
  vector<int> c(n);
  for (auto &x : c) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> hist(n+1);
  vector<ll> sum(n+1);
  int best = -1;;
  auto add = [&](int u) {
    if (++hist[c[u]] > best) best = hist[c[u]];
    sum[hist[c[u]]] += c[u];
  };
  auto rem = [&](int u) {
    sum[hist[c[u]]--] -= c[u];
    best = -1;
  };
  vector<ll> res(n);
  auto ans = [&](int u) { res[u] = sum[best]; };
  small_to_large(g, add, rem, ans);
  for (int i = 0; i < n; i++)
    cout << res[i] << " \n"[i == n-1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
