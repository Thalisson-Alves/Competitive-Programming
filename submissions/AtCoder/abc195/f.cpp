#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll a, b;
  cin >> a >> b;
  constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
  vector<ll> dp(1 << 20);
  dp[0] = 1;
  for (ll i = a; i <= b; i++) {
    int mask = 0;
    for (int j = 0; j < 20; j++) {
      if (i % primes[j] == 0)
        mask |= 1 << j;
    }
    for (int last = (1 << 20) - 1; ~last; --last) {
      if (mask & last) continue;
      dp[last ^ mask] += dp[last];
    }
  }

  ll res = 0;
  for (int i = 0; i < (1 << 20); i++)
    res += dp[i];
  cout << res << '\n';
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
