#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, ll>> es(m);
  for (auto &[u, v, w] : es) cin >> u >> v >> w, --u, --v;
  vector<array<int, 3>> qs(q);
  vector<bool> rem(m);
  for (auto &[t, x, y] : qs) {
    cin >> t >> x; --x;
    if (t == 2) cin >> y, --y;
    else rem[x] = 1;
  }
  vector<vector<ll>> d(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int i = 0; i < m; i++) if (!rem[i]) {
    auto [u, v, w] = es[i];
    d[u][v] = d[v][u] = min({d[u][v], d[v][u], w});
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] < LLONG_MAX and d[k][j] < LLONG_MAX)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  vector<ll> res;
  while (q--) {
    auto [t, x, y] = qs[q];
    if (t == 1) {
      auto [u, v, w] = es[x];
      d[u][v] = d[v][u] = min({d[u][v], d[v][u], w});
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (d[i][u] < LLONG_MAX and d[v][j] < LLONG_MAX)
            d[i][j] = min(d[i][j], d[i][u] + d[v][j] + w);
          if (d[i][v] < LLONG_MAX and d[u][j] < LLONG_MAX)
            d[i][j] = min(d[i][j], d[i][v] + d[u][j] + w);
        }
      }
    }
    else res.push_back(d[x][y] == LLONG_MAX ? -1 : d[x][y]);
  }
  for (int i = (int)size(res)-1; ~i; --i) cout << res[i] << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
