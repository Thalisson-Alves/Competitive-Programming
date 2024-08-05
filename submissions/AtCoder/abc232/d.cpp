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
  vector<string> mat(n);
  for (auto &x : mat) cin >> x;
  vector<vector<int>> dp(n, vector<int>(m));
  auto dfs = [&](auto &&self, int i, int j) {
    if (i >= n or j >= m or mat[i][j] == '#') return 0;
    auto &res = dp[i][j];
    if (res) return res;
    res = 0;
    res = max(self(self, i+1, j), self(self, i, j+1));
    return ++res;
  };
  cout << dfs(dfs, 0, 0) << '\n';
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
