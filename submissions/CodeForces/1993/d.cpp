#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  if (n < k) {
    sort(begin(v), end(v));
    cout << v[(n-1)/2] << '\n';
    return;
  }

  int size = n%k;
  if (!size) size = k;
  int need = size >> 1;

  vector<int> dp(k);
  auto f = [&](int d) -> bool {
    dp.assign(k, 0);
    for (int i = 0; i < n; i++) {
      auto cur = i%k;
      if (!cur) dp[cur] = max(dp[cur], int(v[i]>=d));
      else dp[cur] = max(dp[cur], dp[cur-1] + (v[i]>=d));
    }
    return dp[size-1] > need;
  };

  int l = 0, r = INT_MAX;
  while (l <= r) {
    auto m = midpoint(l, r);
    if (f(m)) l = m + 1;
    else r = m - 1;
  }
  cout << r << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
