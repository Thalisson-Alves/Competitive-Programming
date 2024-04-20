#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll n;
  int a, x, y;
  cin >> n >> a >> x >> y;
  map<ll, double> memo;
  auto dp = [&](auto &&self, ll value) -> double {
    if (!value) return 0;
    if (memo.count(value)) return memo[value];
    double sum = 1.2 * y;
    for (int i = 2; i <= 6; i++) {
      sum += self(self, value / i) / 5.0;
    }
    return memo[value] = min(x + self(self, value / a), sum);
  };
  cout << fixed << setprecision(10) << dp(dp, n) << '\n';
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
