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
  ll mn = -LLONG_MAX / 10, mx = -mn, add = 0;
  for (int i = 0; i < n; i++) {
    ll a, t;
    cin >> a >> t;
    if (t == 1) {
      mn += a;
      mx += a;
      add += a;
    } else if (t == 2) {
      mn = max(mn, a);
      mx = max(mx, a);
    } else {
      mn = min(mn, a);
      mx = min(mx, a);
    }
  }

  int q;
  cin >> q;
  for (ll x; cin >> x;)
    cout << clamp(x + add, mn, mx) << '\n';
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
