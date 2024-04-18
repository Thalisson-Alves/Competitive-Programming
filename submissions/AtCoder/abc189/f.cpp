#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  bitset<(ll)1e5+1> cant;
  for (int x; cin >> x; cant[x] = 1);
  vector<valarray<double>> dp(n + 1, valarray<double>(2));
  valarray<double> sum = {0.0, 0.0};
  for (int i = n - 1; ~i; --i) {
    sum += dp[i + 1] - dp[min(n, i + m + 1)];
    if (cant[i])
      dp[i] = valarray<double>{0.0, 1.0};
    else
      dp[i] = valarray<double>{1.0, 0.0} + sum / m;
  }

  if (fabs(1 - dp[0][1]) <= 1e-8)
    cout << "-1\n";
  else
    cout << fixed << setprecision(7) << dp[0][0] / (1 - dp[0][1]) << '\n';
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
