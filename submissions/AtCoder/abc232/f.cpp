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
  ll x, y;
  cin >> n >> x >> y;
  vector<ll> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;
  vector<ll> memo(1 << n, -1);
  memo[0] = 0;
  auto dp = [&](auto &&self, int msk) -> ll {
    auto &res = memo[msk];
    if (~res) return res;

    res = LLONG_MAX;
    int pos = n-__builtin_popcount(msk), zeros = 0;
    for (int i = n-1; ~i; --i) {
      if (msk&(1<<i))
        res = min(res, abs(b[pos]-a[i]) * x + y * abs(pos-(i+zeros)) + self(self, msk^(1 << i)));
      else
        zeros++;
    }
    return res;
  };
  cout << dp(dp, (1 << n) - 1) << '\n';
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
