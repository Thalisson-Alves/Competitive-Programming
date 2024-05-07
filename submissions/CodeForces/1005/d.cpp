#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  cin >> s;
  int mods = 0, res = 0;
  for (auto c : s) {
    auto x = (c - '0') % 3;
    if (x == 0 or (mods & (1 << (3-x)))) {
      ++res;
      mods = 0;
    } else {
      if (mods & (1 << x)) x = 3 - x;
      mods |= 1 << x;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}
