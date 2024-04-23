#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  a %= b;
  set<int> vis({a});
  int i;
  for (i = 1; a; i++) {
    if (a < b) a *= 10;
    for (; a < b; i++) {
      a *= 10;
      if (c == 0) {
        cout << i << '\n';
        return;
      }
    }
    auto [d, r] = div(a, b);
    a = r;
    if (d == c) {
      cout << i << '\n';
      return;
    }
    if (!vis.insert(a).second) break;
  }
  if (a == 0 and c == 0) {
    cout << i << '\n';
  } else {
    cout << "-1\n";
  }
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
