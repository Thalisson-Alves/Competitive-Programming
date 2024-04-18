#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> hist(71);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ++hist[x];
  }

  vector<ll> mask(71);
  {
    vector<bool> is_prime(71, 1);
    int cnt = 0;
    for (int i = 2; i <= 70; i++) {
      if (!is_prime[i]) continue;
      for (int j = i; j <= 70; j += i) {
        is_prime[j] = j == i;
        int k = j;
        while (k % i == 0) {
          k /= i;
          mask[j] ^= 1ll << cnt;
        }
      }
      ++cnt;
    }
  }

  constexpr ll mod = 1e9 + 7;
  vector<vector<ll>> dp(2, vector<ll>(1 << 19));
  dp[0][0] = 1;
  for (int i = 0; i <= 70; i++) {
    auto f0 = (hist[i] ? fpow(2, hist[i] - 1, mod) : 1);
    auto f1 = (hist[i] ? f0 : 0);
    for (int msk = 0; msk < (int)dp[0].size(); msk++) {
      (dp[1][msk^mask[i]] += dp[0][msk] * f1) %= mod;
      (dp[1][msk] += dp[0][msk] * f0) %= mod;
    }
    swap(dp[0], dp[1]);
    dp[1].assign(dp[1].size(), 0);
  }
  cout << (dp[0][0] - 1 + mod) % mod << '\n';
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
