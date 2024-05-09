#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 3>> sensors(k);
  for (auto &[a, b, c] : sensors) cin >> a >> b >> c;
  auto inter = [&](int i, int j) {
    ll dx = sensors[i][0] - sensors[j][0];
    ll dy = sensors[i][1] - sensors[j][1];
    ll r = sensors[i][2] + sensors[j][2];
    return hypot(dx, dy) <= r;
  };
  vector<vector<int>> g(k);
  for (int i = 0; i < k; i++) {
    for (int j = i+1; j < k; j++) {
      if (not inter(i, j)) continue;
      g[i].push_back(j);
      g[j].push_back(i);
    }
  }

  vector<bool> vis(k);
  bool L, R, U, D;
  auto dfs = [&](auto &&self, int u) -> void {
    L |= sensors[u][0] - sensors[u][2] <= 0;
    R |= sensors[u][0] + sensors[u][2] >= n;
    U |= sensors[u][1] - sensors[u][2] <= 0;
    D |= sensors[u][1] + sensors[u][2] >= m;
    vis[u] = 1;
    for (auto v : g[u]) if (not vis[v]) {
      self(self, v);
    }
  };
  for (int i = 0; i < k; i++) if (!vis[i]) {
    L = R = U = D = 0;
    dfs(dfs, i);
    if ((L and R) or (D and U) or (L and U) or (R and D)) {
      cout << "N\n";
      return;
    }
  }
  cout << "S\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
