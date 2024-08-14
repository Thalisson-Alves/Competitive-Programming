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
  vector<pair<int, int>> v(n);
  for (auto &[x, y] : v) {
    cin >> x >> y;
    if (x > y) swap(x, y);
  }
  vector<vector<ll>> memo(n, vector<ll>(k+1, -1));
  auto dp = [&](auto &&self, int i, int remain) -> ll {
    if (!remain) return 0;
    if (remain < 0 or i >= n) return INT_MAX;
    auto &res = memo[i][remain];
    if (~res) return res;
    res = INT_MAX;
    res = min(res, self(self, i+1, remain));
    auto [a, b] = v[i];
    res = min(res, self(self, i+1, remain-a-b)+(a*b));
    for (int j = 1, acc = 0; a; j++) {
      acc += a;
      res = min(res, self(self, i+1, remain-j)+acc);
      --b;
      if (a > b) swap(a, b);
    }
    return res;
  };
  auto res = dp(dp, 0, k);
  cout << (res >= INT_MAX ? -1 : res) << '\n';
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
