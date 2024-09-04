#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  vector<vector<vector<ll>>> memo(31, vector<vector<ll>>(31, vector<ll>(51, -1)));
  auto dfs = [&](auto &&self, int i, int j, int rem) -> ll {
    if (i*j<rem) return INT_MAX;
    auto &res = memo[i][j][rem];
    if (~res) return res;
    if (i*j == rem or rem == 0) return res = 0;
    res = INT_MAX;
    for (int c = 1; c < i; c++) {
      auto nr = rem-(i-c)*j;
      res = min(res, self(self, c, j, (nr>=0?nr:rem)) + j*j);
      if (nr>=0) res = min(res, self(self, c, j, rem) + j*j);
    }
    for (int c = 1; c < j; c++) {
      auto nr = rem-(j-c)*i;
      res = min(res, self(self, i, c, (nr>=0?nr:rem)) + i*i);
      if (nr>=0) res = min(res, self(self, i, c, rem) + i*i);
    }
    return res;
  };
  for (int i = 30; ~i; --i) {
    for (int j = 30; ~j; --j) {
      for (int k = 50; ~k; --k) {
        dfs(dfs, i, j, k);
      }
    }
  }
  int t; cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << memo[n][m][k] << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
