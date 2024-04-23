#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  int tot = n - m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    tot -= (a != b);
  }
  constexpr ll mod = 1e9 + 7;
  vector<ll> dp(tot+2);
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= tot; i++) {
    dp[i] = (dp[i-1] + 2ll * ((i - 1) * dp[i-2]) % mod) % mod;
  }
  cout << dp[tot] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
