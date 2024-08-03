#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> v(n);
  for (auto &x : v) {
    int k; cin >> k;
    x.resize(k);
    for (auto &y : x) cin >> y;
  }
  auto dfs = [&](auto &&self, int i, ll tot) -> ll {
    if (i >= n) return tot == m;
    if (tot > m) return 0;
    ll res = 0;
    for (auto x : v[i]) {
      if (tot <= m/x)
        res += self(self, i+1, tot*x);
    }
    return res;
  };
  cout << dfs(dfs, 0, 1) << '\n';
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
