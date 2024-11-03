#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll aliens_trick(auto &&f, ll k, int r=INT_MAX) {
  int l = 0;
  while (l <= r) {
    int mid = midpoint(l, r);
    if (f(mid).second > k) l = mid + 1;
    else r = mid - 1;
  }
  return f(l).first - k * l;
};

void solve() {
  int n, k, l;
  cin >> n >> k >> l;
  vector<bool> v(n);
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    v[i] = isupper(c);
  }
  auto f = [&](int cost) {
    vector<pair<int, int>> dp(n+1, {INT_MAX, INT_MAX});
    dp[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
      dp[i] = {dp[i-1].first + v[i-1], dp[i-1].second};
      int lo = max(0, i-l);
      dp[i] = min(dp[i], make_pair(dp[lo].first + cost, dp[lo].second + 1));
    }
    return dp[n];
  };
  int res = (int)aliens_trick(f, k, n);
  for (int i = 0; i < n; i++) v[i] = !v[i];
  res = min(res, (int)aliens_trick(f, k, n));
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
