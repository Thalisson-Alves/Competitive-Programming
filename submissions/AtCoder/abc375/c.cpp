#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n; cin >> n;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  vector<string> res = g;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = i, y = j;
      for (int k = 0; k <= min({i,j,n-1-i,n-1-j})%4; k++)
        tie(x, y) = make_pair(y, n-1-x);
      res[x][y] = g[i][j];
    }
  }
  for (auto x : res) cout << x << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
