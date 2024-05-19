#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  constexpr int v[][4] = {
    {1, 2, 1, 0},
    {2, 1, 0, 1}
  };
  auto [dx, rx] = div(c - a, 4);
  auto sx = (a % 4 + 4) % 4;
  auto ax = [&](int i) -> int {
    int res = dx;
    for (int off = 0; off < rx; off++) {
      res += ((off + sx) % 4 == i);
    }
    return res;
  };
  auto [dy, ry] = div(d - b, 2);
  auto sy = (d % 2 + 2) % 2;
  auto ay = [&](int i) -> int {
    int res = dy;
    for (int off = 0; off < ry; off++) {
      res += ((off + sy) % 2 == i);
    }
    return res;
  };
  ll res = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      res += 1ll * ax(j) * ay(i) * v[i][j];
    }
  }
  cout << res << '\n';
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
