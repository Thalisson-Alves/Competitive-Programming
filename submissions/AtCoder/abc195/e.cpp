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
  string s, t;
  cin >> s >> t;

  vector<vector<bool>> dp(n + 1, vector<bool>(7));
  dp[n][0] = 1;
  for (int i = n - 1; ~i; --i) {
    for (int j = 0; j < 7; j++) {
      auto a = dp[i + 1][(j * 10) % 7];
      auto b = dp[i + 1][(j * 10 + s[i] - '0') % 7];
      dp[i][j] = (t[i] == 'T' ? a or b : a and b);
    }
  }
  cout << (dp[0][0] ? "Takahashi" : "Aoki") << '\n';
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
