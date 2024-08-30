#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll res = 0;
  auto dfs = [&](auto &&self, int u, int p, int d, unordered_map<int, int> &bc) -> void {
    unordered_map<int, int> ch;
    bc = {{d, 1}};
    for (auto v : g[u]) if (v != p) {
      self(self, v, u, d+1, ch);
      if (size(bc) < size(ch)) swap(bc, ch);
      for (auto [i, j] : ch) {
        if (abs(i-d) <= k) res += 1ll * bc[d+k-abs(i-d)] * j;
      }
      for (auto [i, j] : ch) bc[i] += j;
    }
  };
  unordered_map<int, int> st;
  dfs(dfs, 0, -1, 0, st);
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
