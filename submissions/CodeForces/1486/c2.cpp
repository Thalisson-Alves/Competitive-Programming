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
  cout << "? 1 " << n << endl;
  int init; cin >> init;
  bool right = init == 1;
  int l = 1, r = n;
  if (!right) {
    cout << "? 1 " << init << endl;
    int x; cin >> x;
    right = x != init;
  }
  if (!right) {
    r = init - 1;
    while (l <= r) {
      auto m = midpoint(l, r);
      cout << "? " << m << ' ' << n << endl;
      int x; cin >> x;
      if (x == init) l = m + 1;
      else r = m - 1;
    }
    cout << "! " << r << endl;
  } else {
    l = init + 1;
    while (l <= r) {
      auto m = midpoint(l, r);
      cout << "? 1 " << m << endl;
      int x; cin >> x;
      if (x == init) r = m - 1;
      else l = m + 1;
    }
    cout << "! " << l << endl;
  }
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
