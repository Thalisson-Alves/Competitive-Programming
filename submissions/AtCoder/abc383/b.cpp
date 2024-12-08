#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  int res = 0;
  auto ch = [&](int i1, int j1, int i2, int j2) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) if (g[i][j] == '.') {
        cnt += (abs(i1-i) + abs(j1-j) <= d) or (abs(i2-i)+abs(j2-j) <= d);
      }
    }
    return cnt;
  };
  for (int i1 = 0; i1 < n; i1++) {
    for (int j1 = 0; j1 < m; j1++) {
      if (g[i1][j1] != '.') continue;
      for (int i2 = 0; i2 < n; i2++) {
        for (int j2 = 0; j2 < m; j2++) {
          if (g[i2][j2] != '.') continue;
          res = max(res, ch(i1, j1, i2, j2));
        }
      }
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
