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
  using mat = vector<vector<ll>>;
  mat d(n, vector<ll>(n, LLONG_MAX));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    d[u][v] = min(d[u][v], (ll)w);
  }
  auto prod = [&](mat &a, const mat &b) {
    mat res(n, vector<ll>(n, LLONG_MAX));
    for (int l = 0; l < n; l++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (a[i][l] != LLONG_MAX and b[l][j] != LLONG_MAX)
            res[i][j] = min(res[i][j], a[i][l] + b[l][j]);
        }
      }
    }
    swap(a, res);
  };
  auto pow = [&](mat a, int p) {
    mat res(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) res[i][i] = 0;
    while (p) {
      if (p&1) prod(res, a);
      prod(a, a);
      p >>= 1;
    }
    return res;
  };
  auto res = pow(d, k)[0][n-1];
  cout << (res == LLONG_MAX ? -1 : res) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
