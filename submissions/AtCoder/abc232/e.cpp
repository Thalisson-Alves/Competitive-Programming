#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int h, w, k, x1, y1, x2, y2;
  cin >> w >> h >> k >> x1 >> y1 >> x2 >> y2;
  constexpr ll mod = 998244353;
  vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(2, vector<ll>(2)));
  dp[0][x1 == x2][y1 == y2] = 1;
  for (int i = 1; i <= k; i++) {
    auto &cur = dp[i & 1];
    auto &prev = dp[~i & 1];
    cur[0][0] = cur[0][1] = cur[1][0] = cur[1][1] = 0;
    for (int ix = 0; ix < 2; ix++) {
      for (int iy = 0; iy < 2; iy++) {
        if (ix)
          (cur[0][iy] += prev[ix][iy] * (w - 1)) %= mod;
        else {
          (cur[0][iy] += prev[ix][iy] * (w - 2) % mod) %= mod;
          (cur[1][iy] += prev[ix][iy]) %= mod;
        }

        if (iy)
          (cur[ix][0] += prev[ix][iy] * (h - 1)) %= mod;
        else {
          (cur[ix][0] += prev[ix][iy] * (h - 2) % mod) %= mod;
          (cur[ix][1] += prev[ix][iy]) %= mod;
        }
      }
    }
  }
  cout << dp[k&1][1][1] << '\n';
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
