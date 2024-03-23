#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> order(n);
  int timer = 0;
  auto dfs = [&](auto &&self, int u, int p) -> void {
    order[u] = timer++;
    for (auto v : g[u]) if (v != p) {
      self(self, v, u);
    }
  };
  dfs(dfs, 0, -1);

  vector<int> leafs;
  for (int i = 0; i < n; i++) if (g[i].size() == 1) {
    leafs.push_back(i);
  }
  sort(leafs.begin(), leafs.end(), [&](auto a, auto b) { return order[a] < order[b]; });

  vector<pair<int, int>> res;
  int mid = (int)leafs.size() / 2;
  for (int i = 0; i < mid; i++) {
    res.emplace_back(leafs[i], leafs[i + mid]);
  }

  if (leafs.size() & 1) {
    res.emplace_back(leafs[0], leafs.back());
  }

  cout << res.size() << '\n';
  for (auto [a, b] : res) cout << a + 1 << ' ' << b + 1 << '\n';
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
