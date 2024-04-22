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
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  int mn = *min_element(v.begin(), v.end());
  unordered_map<int, int> dp;
  for (auto x : v) {
    for (int i = 1; i < mn and 1ll*i*i <= x; i++) if (x % i == 0) {
      if (x/i < mn) {
        auto &memo = dp[x/i];
        memo = gcd(memo, x);
      }
      auto &memo = dp[i];
      memo = gcd(memo, x);
    }
  }

  int res = 1;
  for (auto [i, x] : dp) {
    res += i == x;
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
