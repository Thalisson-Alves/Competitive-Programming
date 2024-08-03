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
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  int memo[51][51][51][51];
  memset(memo, -1, sizeof(memo));
  auto dp = [&](auto &&self, int l, int r, int d, int u) -> int {
    if (r < l or u < d) return 0;
    auto &res = memo[l][r][d][u];
    if (~res) return res;
    res = max(u-d+1, r-l+1);
    for (int i = d; i <= u; i++) {
      bool ok = 1;
      for (int j = l; ok and j <= r; j++)
        ok &= v[i][j] == '.';
      if (ok) res = min(res, self(self, l, r, d, i-1) + self(self, l, r, i+1, u));
    }
    for (int i = l; i <= r; i++) {
      bool ok = 1;
      for (int j = d; ok and j <= u; j++)
        ok &= v[j][i] == '.';
      if (ok) res = min(res, self(self, l, i-1, d, u) + self(self, i+1, r, d, u));
    }
    return res;
  };
  cout << dp(dp, 0, n-1, 0, n-1) << '\n';
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
