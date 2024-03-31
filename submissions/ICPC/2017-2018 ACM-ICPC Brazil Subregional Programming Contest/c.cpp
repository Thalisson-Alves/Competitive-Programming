#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, l;
  cin >> n >> l;
  ll lc = 1;
  while (n--) {
    int x;
    cin >> x;
    lc = lcm(lc, x);
  }

  int res = 1;
  ll best = lc;
  for (int i = 2; i <= 1e6; i++) {
    auto nxt = lcm(lc, i);
    if (best < nxt and nxt <= l)
      res = i, best = nxt;
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
