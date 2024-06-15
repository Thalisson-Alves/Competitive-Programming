#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int x;
  cin >> x;
  int res = -1;
  if (x < 40) res = 40 - x;
  else if (x < 70) res = 70-x;
  else if (x < 90) res = 90-x;
  else {
    cout << "expert\n";
    return;
  }
  cout << res << '\n';
}

// clang-format off
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
