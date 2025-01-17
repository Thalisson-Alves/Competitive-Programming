#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (auto &x : p) cin >> x;
  vector<vector<double>> dp(n+1, vector<double>(n+1));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    double k = p[i] / 100.0;
    for (int j = 0; j <= n; j++) {
      dp[i+1][j] = (j ? dp[i][j-1] : 0) * k + dp[i][j] * (1 - k);
    }
  }
  vector<double> dp2(m+1);
  for (int i = m-1; ~i; --i) {
    dp2[i] = 1;
    for (int j = 1; j <= n; j++)
      dp2[i] += dp[n][j] * dp2[min(m, i+j)];
    dp2[i] /= (1 - dp[n][0]);
  }
  cout << fixed << setprecision(10) << dp2[0] << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
