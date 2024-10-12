#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  int cx = 0, cy = 0;
  long double res = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    res += hypotl(cx-x, cy-y);
    cx=x,cy=y;
  }
  res += hypotl(cx,cy);
  cout << fixed << setprecision(10) << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}
