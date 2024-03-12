#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

constexpr ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}

void solve()
{
  int n;
  cin >> n;
  auto sum = (n * (n+1)) >> 1;
  if (sum & 1) {
    cout << "0\n";
    return;
  }
  sum >>= 1;
  vector<vector<int>> memo(n+1, vector<int>(sum+1, -1));
  constexpr int mod = 1e9+7;
  auto dp = [&](auto &&self, int i, int x) -> int {
    if (x == 0) return 1;
    if (i > n) return 0;
    auto &res = memo[i][x];
    if (~res) return res;
    res = self(self, i+1, x);
    if (x >= i) res = (res + self(self, i+1, x-i)) % mod;
    return res;
  };
  cout << (dp(dp, 1, sum) * fpow(2, mod - 2, mod)) % mod << '\n';
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
