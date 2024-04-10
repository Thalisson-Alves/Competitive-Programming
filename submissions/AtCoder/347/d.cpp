#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll x = 0, y = 0;
  for (int i = 0; i < 60; i++) if (c & (1ll << i)) {
    if (!a and !b) {
      cout << "-1\n";
      return;
    }
    if (a > b) {
      x |= (1ll << i);
      --a;
    } else {
      y |= (1ll << i);
      --b;
    }
  }
  if (a != b) {
    cout << "-1\n";
    return;
  }

  for (int i = 0; a and i < 60; i++) {
    if (!(x & (1ll << i)) and !(y & (1ll << i))) {
      x |= (1ll << i);
      y |= (1ll << i);
      --a;
    }
  }

  if (a) {
    cout << "-1\n";
  } else {
    cout << x << ' ' << y << '\n';
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
