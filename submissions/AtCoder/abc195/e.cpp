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

  vector<vector<bool>> dp(2, vector<bool>(7));
  dp[1][0] = 1;
  for (int i = n - 1; ~i; --i) {
    for (int j = 0; j < 7; j++) {
      auto a = dp[1][(j * 10) % 7];
      auto b = dp[1][(j * 10 + s[i] - '0') % 7];
      dp[0][j] = (t[i] == 'T' ? a or b : a and b);
    }
    swap(dp[0], dp[1]);
  }
  cout << (dp[1][0] ? "Takahashi" : "Aoki") << '\n';
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
