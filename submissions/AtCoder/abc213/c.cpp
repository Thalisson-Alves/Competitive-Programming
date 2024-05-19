#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> a(n);
  set<int> xs, ys;
  for (auto &[x, y] : a) cin >> x >> y, xs.insert(x), ys.insert(y);
  map<int, int> mpx, mpy;
  int id = 1;
  for (auto x : xs) mpx[x] = id++;
  id = 1;
  for (auto y : ys) mpy[y] = id++;
  for (auto [x, y] : a) cout << mpx[x] << ' ' << mpy[y] << '\n';
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
