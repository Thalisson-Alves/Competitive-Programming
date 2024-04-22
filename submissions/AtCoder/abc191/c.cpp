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
  vector<string> v(2*n);
  for (int i = 0; i < n; i++) {
    char c = 0;
    for (int j = 0; j < m; j++) {
      cin >> c;
      v[i<<1] += c;
      v[i<<1] += c;
    }
    v[i<<1|1] = v[i<<1];
  }
  n <<= 1;
  m <<= 1;
  constexpr int dir1[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  constexpr int dir2[][2] = {{-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

  int res = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (v[i][j] == '.') continue;
      int cnt = 0;
      for (auto [dx, dy] : dir1) {
        int x = dx + i;
        int y = dy + j;
        cnt += (v[x][y] == '#');
      }
      res += (cnt == 2);

      if (cnt == 4) {
        cnt = 0;
        for (auto [dx, dy] : dir2) {
          int x = dx + i;
          int y = dy + j;
          cnt += (v[x][y] == '#');
        }
        res += (cnt == 3);
      }
    }
  }
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
