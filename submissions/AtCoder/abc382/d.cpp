#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> cur;
  vector<vector<int>> res;
  auto dfs = [&](auto &&self, int i, int last) -> void {
    if (i >= n) {
      res.emplace_back(cur);
      return;
    }
    for (int j = last + 10; j + 10 * (n-i-1) <= m; j++) {
      cur.push_back(j);
      self(self, i+1, j);
      cur.pop_back();
    }
  };
  dfs(dfs, 0, -9);
  cout << res.size() << '\n';
  for (auto &x : res) {
    for (int i = 0; i < n; i++) cout << x[i] << " \n"[i == n-1];
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}
