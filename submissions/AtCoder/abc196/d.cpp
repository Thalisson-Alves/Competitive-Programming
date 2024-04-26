#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  vector<vector<bool>> mat(h, vector<bool>(w));
  auto dfs = [&](auto &&self, int i, int j, int ca, int cb) -> int {
    if (j == w) return self(self, i+1, 0, ca, cb);
    if (i == h) return 1;
    if (mat[i][j]) return self(self, i, j+1, ca, cb);

    int res = 0;
    if (ca and w - j >= 2 and !mat[i][j+1]) {
      mat[i][j] = mat[i][j+1] = 1;
      res += self(self, i, j+2, ca-1, cb);
      mat[i][j] = mat[i][j+1] = 0;
    }
    if (ca and h - i >= 2 and !mat[i+1][j]) {
      mat[i][j] = mat[i+1][j] = 1;
      res += self(self, i, j+1, ca-1, cb);
      mat[i][j] = mat[i+1][j] = 0;
    }
    if (cb) {
      mat[i][j] = 1;
      res += self(self, i, j+1, ca, cb-1);
      mat[i][j] = 0;
    }
    return res;
  };
  cout << dfs(dfs, 0, 0, a, b) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
