#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<array<int, 2>> v(n);
  for (auto &[a, b] : v) cin >> a >> b;
  vector<vector<int>> dp(n+1, vector<int>(x+1, y+1));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int cnt = i; ~cnt; --cnt) {
      for (int sx = v[i][0]; sx<=x; sx++) {
        dp[cnt+1][sx] = min(dp[cnt+1][sx], dp[cnt][sx-v[i][0]]+v[i][1]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= x; j++) {
      if (dp[i][j] <= y)
        res = max(res, i+1);
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
