#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, w;
  cin >> n >> w;
  constexpr int m = 1e5;
  vector<vector<ll>> dp(2, vector<ll>(m+1, w+1));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int a, b; cin >> a >> b;
    dp[1] = dp[0];
    for (int j = 0; j <= m-b; j++) {
      dp[1][j+b] = min(dp[1][j+b], dp[0][j] + a);
    }
    swap(dp[0], dp[1]);
  }
  for (int i = m; ~i; --i) {
    if (dp[0][i] <= w) {
      cout << i << '\n';
      return;
    }
  }
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
