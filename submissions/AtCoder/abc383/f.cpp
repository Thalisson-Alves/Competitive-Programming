#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> mp(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    mp[--c].emplace_back(a, b);
  }
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i+1] = dp[i];
    for (auto [a, b] : mp[i]) {
      for (int j = m; j >= a; --j) {
        if (~dp[i][j-a]) dp[i+1][j] = max(dp[i+1][j], dp[i][j-a] + b + k);
        if (~dp[i+1][j-a]) dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-a] + b);
      }
    }
  }
  cout << *max_element(begin(dp[n]), end(dp[n])) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
