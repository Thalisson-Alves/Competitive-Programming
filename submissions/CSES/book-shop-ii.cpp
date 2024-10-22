#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n), s(n), k(n);
  for (auto &x : h) cin >> x;
  for (auto &x : s) cin >> x;
  for (auto &x : k) cin >> x;
  vector<ll> dp(m+1, LLONG_MIN);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int l = 1; k[i] > 0; l <<= 1) {
      int got = min(l, k[i]);
      k[i] -= got;
      for (int j = m; j-got*h[i] >= 0; --j)
        if (dp[j-got*h[i]] != -1)
          dp[j] = max(dp[j], dp[j-got*h[i]]+got*s[i]);
    }
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
