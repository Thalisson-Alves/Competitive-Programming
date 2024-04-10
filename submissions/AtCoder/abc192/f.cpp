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
  vector<ll> v(n);
  for (auto &x : v)
    cin >> x;

  ll mp[101][101][101];
  ll res = LLONG_MAX;
  for (int total_size = 1; total_size <= n; total_size++) {
    memset(mp, 0, sizeof(mp));
    auto dp = [&](auto &&self, int i, int remain, ll cong) -> ll {
      if (remain == 0) return cong ? -1 : 0;
      if (i >= n) return -1;
      auto &memo = mp[i][remain][cong];
      if (memo) return memo;
      memo = self(self, i + 1, remain, cong);
      cong = ((cong - v[i]) % total_size + total_size) % total_size;
      auto value = self(self, i + 1, remain - 1, cong);
      if (~value) memo = max(memo, value + v[i]);
      return memo;
    };
    auto value = dp(dp, 0, total_size, m % total_size);
    if (~value)
      res = min(res, (m - value) / total_size);
  }
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

