#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<vector<ll>> p(n, vector<ll>(n));
  for (auto &row : p) for (auto &x : row) cin >> x;
  vector<vector<ll>> r(n, vector<ll>(n-1));
  for (auto &row : r) for (auto &x : row) cin >> x;
  vector<vector<ll>> d(n-1, vector<ll>(n));
  for (auto &row : d) for (auto &x : row) cin >> x;

  vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {LLONG_MAX, 0}));
  dp[0][0] = {0, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<vector<ll>> dist(i+1, vector<ll>(j+1, LLONG_MAX));
      dist[i][j] = 0;
      for (int x = i; ~x; --x) {
        for (int y = j; ~y; --y) {
          if (x == i and y == j) continue;
          if (x < i) dist[x][y] = min(dist[x][y], d[x][y] + dist[x+1][y]);
          if (y < j) dist[x][y] = min(dist[x][y], r[x][y] + dist[x][y+1]);
          auto c = max(0ll, dist[x][y] - dp[x][y].second + p[x][y] - 1) / p[x][y];
          auto t = dp[x][y].first + c + i - x + j - y;
          auto m = dp[x][y].second + c * p[x][y] - dist[x][y];
          if (t < dp[i][j].first or (t == dp[i][j].first and m > dp[i][j].second))
            dp[i][j] = {t, m};
        }
      }
    }
  }
  cout << dp[n-1][n-1].first << '\n';
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
