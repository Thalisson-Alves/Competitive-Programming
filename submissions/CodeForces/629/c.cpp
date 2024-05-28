#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, _; string s;
  cin >> n >> _ >> s;
  if ((n += 1 - (int)s.size()) <= 0) {
    cout << "0\n";
    return;
  }

  int pref = 0, suf = 0;
  for (auto c : s) {
    suf += (c == '(') * 2 - 1;
    pref = min(pref, suf);
  }

  constexpr ll mod = 1e9 + 7;

  vector<vector<array<ll, 2>>> dp(2, vector<array<ll, 2>>(n, {0}));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[1][j][false] = (j ? dp[0][j-1][false] : 0);
      if (j + 1 < (int)dp[1].size())
        (dp[1][j][false] += dp[0][j+1][false]) %= mod;

      dp[1][j][true] = (j ? dp[0][j-1][true] : 0);
      if (j + 1 < (int)dp[1].size())
        (dp[1][j][true] += dp[0][j+1][true]) %= mod;

      if (j >= suf-pref and j >= suf and j-suf < (int)dp[1].size()) (dp[1][j][true] += dp[0][j-suf][false]) %= mod;
    }
    swap(dp[0], dp[1]);
  }
  cout << dp[0][0][true] << '\n';
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
