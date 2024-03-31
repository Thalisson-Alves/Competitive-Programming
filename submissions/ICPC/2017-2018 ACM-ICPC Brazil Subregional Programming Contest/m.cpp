#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int res = INT_MAX;
  for (int i = 0; i < 3; i++) {
    int cost = 0;
    for (int j = 0; j < 3; j++)
      cost += 2 * abs(i - j) * a[j];
    res = min(res, cost);
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
