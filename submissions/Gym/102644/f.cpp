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
  vector<vector<ll>> g(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[--u][--v] = w;
  }
  auto op = [&](auto &a, const auto &b) {
    vector<vector<ll>> d(n, vector<ll>(n, LLONG_MAX));
    vector<vector<bool>> nc(n, vector<bool>(n));
    for (int l = 0; l < n; l++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (a[i][l] < LLONG_MAX and b[l][j] < LLONG_MAX) {
            d[i][j] = min(d[i][j], a[i][l] + b[l][j]);
          }
        }
      }
    }
    a = d;
  };
  auto pow = [&](auto b, ll power) {
    vector<vector<ll>> res(n, vector<ll>(n));
    vector<vector<bool>> cr(n, vector<bool>(n, 1));
    while (power) {
      if (power & 1) op(res, b);
      op(b, b);
      power >>= 1;
    }
    return res;
  };
  g = pow(g, k);
  ll res = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res = min(res, g[i][j]);
    }
  }
  if (res == LLONG_MAX) cout << "IMPOSSIBLE\n";
  else cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
