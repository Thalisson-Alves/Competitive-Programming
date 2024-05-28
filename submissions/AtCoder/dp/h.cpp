#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (auto &x : v) cin >> x;
  constexpr ll mod = 1e9 + 7;
  vector<vector<ll>> dp(n, vector<ll>(m));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '#') continue;
      if (i) dp[i][j] = dp[i-1][j];
      if (j) (dp[i][j] += dp[i][j-1]) %= mod;
    }
  }
  cout << dp[n-1][m-1] << '\n';
}

// clang-format off
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
