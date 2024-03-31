#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int t, n, m;
  cin >> t >> m >> n;
  n -= m - 1;
  vector<vector<ll>> dp(t, vector<ll>(n));
  for (int i = 0; i < n; i++)
    dp[0][i] = 1;
  constexpr ll mod = 1e9 + 7;
  for (int i = 0; i < t - 1; i++) {
    for (int j = 0; j < n; j++) {
      if (j)
        (dp[i+1][j-1] += dp[i][j]) %= mod;
      if (j+1 < n)
        (dp[i+1][j+1] += dp[i][j]) %= mod;
    }
  }
  ll res = 0;
  for (int i = 0; i < n; i++)
    (res += dp.back()[i]) %= mod;
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
