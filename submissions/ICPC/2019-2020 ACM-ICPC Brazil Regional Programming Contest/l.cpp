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
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      g[i][j] = (c == 'G');
    }
  }

  vector<vector<int>> dp(n, vector<int>(m));
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0, prev = -2, pos = -1; j < m; j++) {
      if (prev != g[i][j]) {
        prev = g[i][j];
        pos = j;
      }
      if (i and j and g[i-1][j] == g[i-1][j-1])
        dp[i][j] = min({j - pos + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1});
      dp[i][j] = max(1, dp[i][j]);
      res = max(res, dp[i][j] * dp[i][j]);
    }
  }
  cout << res << '\n';
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
