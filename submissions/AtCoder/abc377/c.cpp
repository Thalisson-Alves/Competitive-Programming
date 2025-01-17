#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> cant;
  constexpr int dir[][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
  for (int _ = 0; _ < m; _++) {
    int i, j;
    cin >> i >> j;
    cant.emplace(i, j);
    for (auto [dx, dy] : dir) {
      int x = dx + i;
      int y = dy + j;
      if (0 < x and x <= n and 0 < y and y <= n)
        cant.emplace(x, y);
    }
  }
  cout << (ll)n*n-cant.size() << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
