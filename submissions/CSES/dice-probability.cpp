#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<double> dp(b+1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = b; ~j; --j) {
      double sum = 0;
      for (int k = max(0, j-6); k < j; ++k) sum += dp[k];
      dp[j] = sum / 6.0;
    }
  }
  cout << fixed << setprecision(6) << accumulate(begin(dp)+a, end(dp), 0.0) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
