#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int k;
  cin >> k;
  constexpr int n = 8;
  double exp[n][n];
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) exp[i][j] = 1;
  constexpr int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double dp[n][n], dp_next[n][n];
      memset(dp, 0, sizeof(dp_next));
      dp[i][j] = 1;
      for (int kk = 0; kk < k; kk++) {
        memset(dp_next, 0, sizeof(dp_next));
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < n; y++) {
            int tot = 0;
            for (auto [dx, dy] : dir) {
              int nx = dx + x;
              int ny = dy + y;
              tot += (0 <= nx and nx < n and 0 <= ny and ny < n);
            }
            for (auto [dx, dy] : dir) {
              int nx = dx + x;
              int ny = dy + y;
              if (0 <= nx and nx < n and 0 <= ny and ny < n)
                dp_next[nx][ny] += dp[x][y] / tot;
            }
          }
        }
        swap(dp, dp_next);
      }
      for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
          exp[x][y] *= 1 - dp[x][y];
        }
      }
    }
  }
  double res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      res += exp[i][j];
  cout << fixed << setprecision(6) << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
