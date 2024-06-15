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
  int X, Y;
  cin >> X >> Y;
  vector<array<int, 2>> v(n);
  for (auto &[a, b] : v) cin >> a >> b;
  vector<vector<vector<int>>> memo(n, vector<vector<int>>(X+1, vector<int>(Y+1, -1)));
  auto dp = [&](auto &&self, int i, int rx, int ry) -> int {
    if (!(rx + ry)) return 0;
    if (i >= n) return n + 1;
    auto &res = memo[i][rx][ry];
    if (~res) return res;
    return res = min({self(self, i+1, rx, ry), self(self, i+1, max(rx-v[i][0], 0), max(ry-v[i][1], 0)) + 1});
  };
  auto res = dp(dp, 0, X, Y);
  cout << (res == n + 1 ? -1 : res) << '\n';
}

// clang-format off
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
