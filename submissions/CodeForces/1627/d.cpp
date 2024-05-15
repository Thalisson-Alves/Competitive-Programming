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
  vector<bool> has(1e6+1);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    has[x] = 1;
    mx = max(mx, x);
  }

  vector<int> dp(mx+1);
  int res = 0;
  for (int i = 1; i <= mx; i++) {
    for (int j = i; j <= mx; j += i) {
      if (has[j]) dp[i] = gcd(dp[i], j);
    }
    res += dp[i] == i and !has[i];
  }
  cout << res << '\n';
}

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
